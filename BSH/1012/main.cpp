#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    ios::sync_with_stdio(false);

    int testcase;

    cin >> testcase;

    for (int T = 0; T < testcase; T++) {

        int col, row, cabbage;
        int ans = 0;

        cin >> col >> row >> cabbage;

        vector<vector<bool>> board(row, vector<bool>(col, false));
        vector<vector<bool>> visit(row, vector<bool>(col, false));


        int x, y;
        for (int i = 0; i < cabbage; i++) {

            cin >> x >> y;

            board[y][x] = true;

        }

        for (y = 0; y < row; y++) {
            for (x = 0; x < col; x++) {
                if (!visit[y][x] && board[y][x]) {
                    ans += 1;
                    queue<pair<int, int>> bfs_q;
                    bfs_q.push({x, y});

                    while (!bfs_q.empty()) {

                        pair<int, int> current = bfs_q.front();
                        bfs_q.pop();

                        for (int i = 0; i < 4; i++) {

                            pair<int, int> new_pos = current;
                            new_pos.first += dx[i];
                            new_pos.second += dy[i];

                            if (0 <= new_pos.first && new_pos.first < col
                                && 0 <= new_pos.second && new_pos.second < row
                                && !visit[new_pos.second][new_pos.first]
                                && board[new_pos.second][new_pos.first]) {
                                visit[new_pos.second][new_pos.first] = true;
                                bfs_q.push(new_pos);
                            }


                        }

                    }

                }
            }
        }


        cout << ans << '\n';

    }

    return 0;
}