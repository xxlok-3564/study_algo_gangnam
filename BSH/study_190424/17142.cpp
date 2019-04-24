#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    int board_size, virus_num;
    int ans;
    int all_visit;

    cin >> board_size >> virus_num;

    ans = board_size * board_size + 1;
    all_visit = board_size * board_size;

    vector<vector<int>> init_board(board_size, vector<int>(board_size));
    vector<pair<int, int>> virus_pos;

    for (int y = 0; y < board_size; y++) {
        for (int x = 0; x < board_size; x++) {
            cin >> init_board[y][x];
            if (init_board[y][x] == 2)
                virus_pos.emplace_back(x, y);
            if (init_board[y][x] == 1)
                all_visit -= 1;
        }
    }

    vector<bool> virus_select(virus_pos.size(), false);
    fill(virus_select.end() - virus_num, virus_select.end(), true);

    do {

        vector<vector<int>> board = init_board;
        vector<vector<int>> visit(board_size, vector<int>(board_size, -1));
        queue<pair<int, int>> bfs_q;
        int visit_loc = 0;
        int spent_time = 0;

        for (int i = 0; i < virus_select.size(); i++) {

            if (virus_select[i]) {

                bfs_q.push(virus_pos[i]);
                visit[virus_pos[i].second][virus_pos[i].first] = 0;
                visit_loc += 1;

            }
        }

        while (!bfs_q.empty()) {

            pair<int, int> current = bfs_q.front();
            bfs_q.pop();

            for (int i = 0; i < 4; i++) {
                pair<int, int> new_pos = current;
                new_pos.first += dx[i];
                new_pos.second += dy[i];

                if (0 <= new_pos.first && new_pos.first < board_size
                    && 0 <= new_pos.second && new_pos.second < board_size
                    && visit[new_pos.second][new_pos.first] == -1
                    && (board[new_pos.second][new_pos.first] == 0 || board[new_pos.second][new_pos.first] == 2)) {

                    if (board[new_pos.second][new_pos.first] == 0) {
                        bfs_q.push(new_pos);
                        visit[new_pos.second][new_pos.first] = visit[current.second][current.first] + 1;
                        visit_loc += 1;
                        if (spent_time < visit[new_pos.second][new_pos.first])
                            spent_time = visit[new_pos.second][new_pos.first];
                    } else if (board[new_pos.second][new_pos.first] == 2) {
                        bfs_q.push(new_pos);
                        visit[new_pos.second][new_pos.first] = visit[current.second][current.first] + 1;
                        visit_loc += 1;
                    }

                }
            }

        }

        //모두 방문일때만 ans 업데이트
        if (all_visit == visit_loc && ans > spent_time)
            ans = spent_time;


    } while (next_permutation(virus_select.begin(), virus_select.end()));


    if (ans == board_size * board_size + 1)
        cout << "-1";
    else
        cout << ans;

    return 0;
}