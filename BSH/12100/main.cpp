#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void op_right(vector<vector<int>> &temp, int N) {

    vector<vector<int>> checker(N, vector<int>(N, 0));

    for (int y = 0; y < N; y++) {
        int checker_idx = N - 1;
        for (int x = N - 1; x >= 0; x--) {

            if (temp[y][x] != 0) {
                bool change = true;
                for (int new_x = x - 1; new_x >= 0; new_x--) {

                    if (temp[y][x] == temp[y][new_x]) {
                        checker[y][checker_idx] = temp[y][x] * 2;
                        checker_idx--;
                        temp[y][x] = temp[y][new_x] = 0;
                        change = false;
                        break;
                    } else if (temp[y][x] != temp[y][new_x] && temp[y][new_x] != 0) {
                        change = true;
                        break;
                    }

                }
                if (change) {
                    checker[y][checker_idx] = temp[y][x];
                    checker_idx--;
                }

            }

        }

    }

    temp = checker;

}

void op_left(vector<vector<int>> &temp, int N) {

    vector<vector<int>> checker(N, vector<int>(N, 0));

    for (int y = 0; y < N; y++) {
        int checker_idx = 0;
        for (int x = 0; x < N; x++) {
            if (temp[y][x] != 0) {
                bool change = true;
                for (int new_x = x + 1; new_x < N; new_x++) {

                    if (temp[y][x] == temp[y][new_x]) {
                        checker[y][checker_idx] = temp[y][x] * 2;
                        checker_idx++;
                        temp[y][x] = temp[y][new_x] = 0;
                        change = false;
                        break;
                    } else if (temp[y][x] != temp[y][new_x] && temp[y][new_x] != 0) {
                        change = true;
                        break;
                    }

                }
                if (change) {
                    checker[y][checker_idx] = temp[y][x];
                    checker_idx++;
                }
            }
        }

    }

    temp = checker;

}

void op_up(vector<vector<int>> &temp, int N) {

    vector<vector<int>> checker(N, vector<int>(N, 0));

    for (int x = 0; x < N; x++) {
        int checker_idx = 0;
        for (int y = 0; y < N; y++) {
            if (temp[y][x] != 0) {
                bool change = true;
                for (int new_y = y + 1; new_y < N; new_y++) {

                    if (temp[y][x] == temp[new_y][x]) {
                        checker[checker_idx][x] = temp[y][x] * 2;
                        checker_idx++;
                        temp[y][x] = temp[new_y][x] = 0;
                        change = false;
                        break;
                    } else if (temp[y][x] != temp[new_y][x] && temp[new_y][x] != 0) {
                        change = true;
                        break;
                    }

                }
                if (change) {
                    checker[checker_idx][x] = temp[y][x];
                    checker_idx++;
                }
            }
        }
    }

    temp = checker;


}

void op_down(vector<vector<int>> &temp, int N) {

    vector<vector<int>> checker(N, vector<int>(N, 0));

    for (int x = 0; x < N; x++) {
        int checker_idx = N - 1;
        for (int y = N - 1; y >= 0; y--) {

            if (temp[y][x] != 0) {
                bool change = true;
                for (int new_y = y - 1; new_y >= 0; new_y--) {
                    if (temp[y][x] == temp[new_y][x]) {
                        checker[checker_idx][x] = temp[y][x] * 2;
                        checker_idx--;
                        temp[y][x] = temp[new_y][x] = 0;
                        change = false;
                        break;
                    } else if (temp[y][x] != temp[new_y][x] && temp[new_y][x] != 0) {
                        change = true;
                        break;
                    }
                }
                if (change) {
                    checker[checker_idx][x] = temp[y][x];
                    checker_idx--;
                }
            }

        }
    }

    temp = checker;

}

void rec(int depth, vector<vector<int>> &board, int N) {

    if (depth == 5) {

        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++)
                if (board[y][x] > ans)
                    ans = board[y][x];

        return;
    }

    for (int i = 0; i < 4; i++) {

        vector<vector<int>> temp = board;

        switch (i) {
            case 0:
                op_right(temp, N);
                rec(depth + 1, temp, N);
                break;

            case 1:
                op_left(temp, N);
                rec(depth + 1, temp, N);
                break;

            case 2:
                op_up(temp, N);
                rec(depth + 1, temp, N);
                break;

            case 3:
                op_down(temp, N);
                rec(depth + 1, temp, N);
                break;

        };
    }

}


int main() {

    int N;

    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];

    rec(0, board, N);

    cout << ans;


    return 0;
}