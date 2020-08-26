#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = numeric_limits<int>::max();

int main() {
    int row, col, num_break = 1;

    cin >> row >> col;

    vector<vector<bool>> board(row, vector<bool>(col));

    char c;
    vector<pair<int, int>> wall_pos;

    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            cin >> c;
            if (c == '1') {
                wall_pos.emplace_back(x, y);
                board[y][x] = true;
            } else {
                board[y][x] = false;
            }
        }
    }

    for (int w = 0; w <= min((int) num_break, (int) wall_pos.size()); w++) {
        vector<bool> select(wall_pos.size(), false);
        fill(select.end() - w, select.end(), true);

        do {

            for (int i = 0; i < select.size(); i++)
                if (select[i]) board[wall_pos[i].second][wall_pos[i].first] = false;

            queue<pair<int, int>> bfs_q;
            vector<vector<int>> visit(row, vector<int>(col, 0));
            bfs_q.push({0, 0});
            visit[0][0] = 1;

            while (!bfs_q.empty()) {

                pair<int, int> current = bfs_q.front();
                bfs_q.pop();
                if (current.first == col - 1 && current.second == row - 1) {
                    if (visit[current.second][current.first] < ans)
                        ans = visit[current.second][current.first];
                }


                for (int i = 0; i < 4; i++) {

                    pair<int, int> new_pos = {current.first + dx[i], current.second + dy[i]};

                    if (0 <= new_pos.first && new_pos.first < col && 0 <= new_pos.second && new_pos.second < row &&
                        !visit[new_pos.second][new_pos.first] && !board[new_pos.second][new_pos.first]) {
                        bfs_q.push(new_pos);
                        visit[new_pos.second][new_pos.first] = visit[current.second][current.first] + 1;
                    }

                }

            }


            for (int i = 0; i < select.size(); i++)
                if (select[i]) board[wall_pos[i].second][wall_pos[i].first] = true;

        } while (next_permutation(select.begin(), select.end()));
    }

    if (ans == numeric_limits<int>::max())
        cout << "-1";
    else
        cout << ans;

    return 0;
}