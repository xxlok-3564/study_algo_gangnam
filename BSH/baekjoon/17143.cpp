#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct shark_info {
    int speed;
    int dir;
    int size;
};

class cmp {

public:
    bool operator()(const shark_info &a, const shark_info &b) {
        return a.size < b.size;
    }

};

int main() {

    int R, C;
    int M;
    int ans = 0;

    cin >> R >> C >> M;

    priority_queue<shark_info, deque<shark_info>, cmp> filter[R][C];
    vector<vector<shark_info>> board(R, vector<shark_info>(C, {0, 0, 0}));

    // (r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다.
    // d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.

    int r, c, s, d, z;
    for (int iter = 0; iter < M; iter++) {

        cin >> r >> c >> s >> d >> z;

        if (r - 1 == 0 && d == 2)
            d = 1;
        else if (r - 1 == R - 1 && d == 1)
            d = 2;
        else if (c == 0 && d == 3)
            d = 4;
        else if (c - 1 == C - 1 && d == 4)
            d = 3;

        board[r - 1][c - 1] = {s, d, z};

    }

    int R_cycle = R * 2 - 2;
    int C_cycle = C * 2 - 2;

    for (int fisher_loc = 0; fisher_loc < C; fisher_loc++) {

        for (int shark_loc = 0; shark_loc < R; shark_loc++) {
            if (board[shark_loc][fisher_loc].size) {

                ans += board[shark_loc][fisher_loc].size;
                board[shark_loc][fisher_loc] = {0, 0, 0};

                break;
            }
        }

        // (r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다.
        // d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.

        //물고기 이동
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (board[y][x].size) {

                    if (board[y][x].dir == 3 || board[y][x].dir == 4) {

                        int real_x;

                        if (0 < x && x < C - 1) {
                            real_x = (board[y][x].dir == 3) ? x : (C - 1 + (C - 1 - x));
                        } else {
                            real_x = x;
                        }

                        real_x += board[y][x].speed;
                        real_x %= C_cycle;

                        if (0 < real_x && real_x < C) {
                            filter[y][real_x].push({board[y][x].speed, 3, board[y][x].size});
                        } else {
                            real_x = (real_x == 0) ? real_x : (C - 1 - (real_x - (C - 1)));
                            filter[y][real_x].push({board[y][x].speed, 4, board[y][x].size});
                        }

                    } else if (board[y][x].dir == 1 || board[y][x].dir == 2) {

                        int real_y;

                        if (0 < y && y < R - 1) {
                            real_y = (board[y][x].dir == 2) ? y : (R - 1 + (R - 1 - y));
                        } else {
                            real_y = y;
                        }

                        real_y += board[y][x].speed;
                        real_y %= R_cycle;

                        if (0 < real_y && real_y < R) {
                            filter[real_y][x].push({board[y][x].speed, 2, board[y][x].size});
                        } else {
                            real_y = (real_y == 0) ? real_y : (R - 1 - (real_y - (R - 1)));
                            filter[real_y][x].push({board[y][x].speed, 1, board[y][x].size});
                        }

                    }
                }
            }
        }

        // 맨 위것 보드에 쓰고, pq 청소
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (!filter[y][x].empty()) {
                    board[y][x] = filter[y][x].top();
                    while (!filter[y][x].empty())
                        filter[y][x].pop();
                } else {
                    board[y][x] = {0, 0, 0};
                }
            }
        }

    }

    cout << ans;

    return 0;
}