#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void make_up_cycle(pair<int, int> &start, vector<pair<int, int>> &up_cycle, int R_left, int R_right, int &C) {

    pair<int, int> dir[4] = {{0,  -1},
                             {1,  0},
                             {0,  1},
                             {-1, 0}};
    int dir_idx = 0;

    pair<int, int> current = start;

    while (1) {
        //더하기

        current.first += dir[dir_idx].first;
        current.second += dir[dir_idx].second;

        if (0 <= current.first && current.first < C
            && R_left <= current.second && current.second < R_right) {

            if (start == current)
                break;

            up_cycle.push_back(current);

        } else {

            current.first -= dir[dir_idx].first;
            current.second -= dir[dir_idx].second;
            dir_idx += 1;

        }
    }


}

void make_down_cycle(pair<int, int> &start, vector<pair<int, int>> &down_cycle, int R_left, int R_right, int &C) {

    pair<int, int> dir[4] = {{0,  1},
                             {1,  0},
                             {0,  -1},
                             {-1, 0}};
    int dir_idx = 0;

    pair<int, int> current = start;

    current.first += dir[dir_idx].first;
    current.second += dir[dir_idx].second;

    while (1) {
        //더하기

        if (0 <= current.first && current.first < C
            && R_left <= current.second && current.second < R_right) {

            if (start == current)
                break;

            down_cycle.push_back(current);
            current.first += dir[dir_idx].first;
            current.second += dir[dir_idx].second;

        } else {

            current.first -= dir[dir_idx].first;
            current.second -= dir[dir_idx].second;
            dir_idx += 1;

        }
    }


}

int main() {

    int R, C, T;

    cin >> R >> C >> T;

    vector<vector<int>> board(R, vector<int>(C, 0));
    vector<pair<int, int>> air_conditional_loc;

    vector<pair<int, int>> up_cycle;
    vector<pair<int, int>> down_cycle;

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cin >> board[y][x];

            if (board[y][x] == -1)
                air_conditional_loc.emplace_back(x, y);
        }
    }

    for (int i = 0; i < 2; i++) {
        if (i == 0)
            make_up_cycle(air_conditional_loc[0], up_cycle, 0, air_conditional_loc[0].second + 1, C);
        else if (i == 1)
            make_down_cycle(air_conditional_loc[1], down_cycle, air_conditional_loc[1].second, R, C);
    }


    for (int time = 0; time < T; time++) {

        vector<vector<int>> dust_spread(R, vector<int>(C, 0));

        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {

                int dust_amount = board[y][x] / 5;
                int dust_dir_num = 0;

                for (int diff = 0; diff < 4; diff++) {

                    if (0 <= x + dx[diff] && x + dx[diff] < C
                        && 0 <= y + dy[diff] && y + dy[diff] < R
                        && board[y + dy[diff]][x + dx[diff]] != -1) {

                        dust_dir_num += 1;
                        dust_spread[y + dy[diff]][x + dx[diff]] += dust_amount;
                    }

                }

                dust_spread[y][x] += (board[y][x] - dust_dir_num * dust_amount);

            }
        }

        for (int i = 0; i < up_cycle.size() - 1; i++)
            dust_spread[up_cycle[i].second][up_cycle[i].first]
                    = dust_spread[up_cycle[i + 1].second][up_cycle[i + 1].first];

        for (int i = 0; i < down_cycle.size() - 1; i++)
            dust_spread[down_cycle[i].second][down_cycle[i].first]
                    = dust_spread[down_cycle[i + 1].second][down_cycle[i + 1].first];

        for (pair<int, int> &loc : air_conditional_loc)
            dust_spread[loc.second][loc.first + 1] = 0;

        board = dust_spread;
    }

    int ans = 0;

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (board[y][x] != -1)
                ans += board[y][x];
        }
    }

    cout << ans;


    return 0;
}