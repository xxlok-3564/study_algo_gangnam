#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int ans;

vector<bool> bfs(const int &row, const int &col, vector<vector<int>> &board, const vector<int, int> &boundary,
                 vector<bool> &key_box) {

    queue<pair<int, int>> bfs_q;
    vector<bool> visit(row * col, false);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (auto &pos: boundary) {
        if (board[pos.second][pos.first] == '.'
            || ('A' <= board[pos.second][pos.first] && board[pos.second][pos.first] <= 'Z'
                && key_box[board[pos.second][pos.first] - 'A'])
                || board[pos.second][pos.first] == '$') {

            if(board[pos.second][pos.first] == '$')
                ans += 1;

            bfs_q.push(pos);
            visit[pos.first + col * pos.second] = true;
        }
    }

    while (!bfs_q.empty()) {

        pair<int, int> current_posistion = bfs_q.front();
        bfs_q.pop();

        for (int i = 0; i < 4; i++) {

            pair<int, int> new_position = current_posistion;
            new_position.first += dx[i];
            new_position.second += dy[i];

            if (0 <= new_position.first && new_position.first < col
                && 0 <= new_position.second && new_position.second < row
                && !visit[new_position.first + col * new_position.second]
                && (board[new_position.second][new_position.first] == '.'
                    || ('a' <= board[new_position.second][new_position.first]
                        && board[new_position.second][new_position.first] <= 'z'
                        && key_box[board[new_position.second][new_position.first] - 'A' + 'a']))) {

                bfs_q.push(new_position);
                visit[new_position.first + col * new_position.second] = true;

            }


        }

    }

    return visit;

}

vector<pair<int, int>> get_start_loc(const int &row, const int &col) {

    pair<int, int> current = {0, 0};
    pair<int, int> fin = {0, 0};
    vector<pair<int, int>> boundary;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int idx = 0;

    boundary.push_back(current);

    while (true) {

        if (0 <= current.first + dx[idx] && current.first + dx[idx] < col
            && 0 <= current.second + dy[idx] && current.second + dy[idx] < row) {

            current.first += dx[idx];
            current.second += dy[idx];

            if (current == fin)
                break;

            boundary.push_back(current);
        } else {
            idx += 1;
        }

    }

    return boundary;

}

int main() {
    int T;
    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {

        int row, col;
        vector<bool> key_box(26, false);

        int ans = 0;

        cin >> row >> col;

        vector<vector<int>> board(row, vector<int>(col));

        char c;
        for (int y = 0; y < row; y++) {
            for (int x = 0; x < col; x++) {
                cin >> c;
                board[y][x] = c;
            }
        }

        string key;
        cin >> key;

        for (char &k : key) {
            if (k != '0')
                key_box[k - 'A'] = true;
        }

        vector<pair<int, int>> boundary = get_start_loc(row, col);


    }

    return 0;
}