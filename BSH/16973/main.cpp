#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool block_exist(pair<int, int> &new_pos, int height, int width, int dir, vector<vector<bool>> &board) {

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    if (dir == 0) {
        for (int y = new_pos.second; y < new_pos.second + height; y++)
            if (board[y][new_pos.first + width - 1]) return true;

        return false;
    } else if (dir == 1) {
        for (int x = new_pos.first; x < new_pos.first + width; x++)
            if (board[new_pos.second + height - 1][x]) return true;

        return false;
    } else if (dir == 2) {
        for (int y = new_pos.second; y < new_pos.second + height; y++)
            if (board[y][new_pos.first]) return true;

        return false;
    } else if (dir == 3) {
        for (int x = new_pos.first; x < new_pos.first + width; x++)
            if (board[new_pos.second][x]) return true;
        return false;
    }

}

bool in_boundary(pair<int, int> &new_pos, int dir, int height, int width, int row, int col) {

    if (dir == 0) {
        return (new_pos.first + width - 1) < col;
    } else if (dir == 1) {
        return (new_pos.second + height - 1) < row;
    } else if (dir == 2) {
        return (new_pos.first >= 0);
    } else if (dir == 3) {
        return (new_pos.second >= 0);
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int row, col;
    int start_row, start_col;
    int end_row, end_col;
    int height, width;

    cin >> row >> col;

    vector<vector<bool>> board(row, vector<bool>(col, false));

    int c;
    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            cin >> c;
            board[y][x] = (bool) c;
        }
    }

    cin >> height >> width >> start_row >> start_col >> end_row >> end_col;
    start_row -= 1;
    start_col -= 1;
    end_row -= 1;
    end_col -= 1;

    queue<pair<int, int>> bfs_q;
    pair<int, int> finish_point = {end_col, end_row};
    vector<vector<int>> visit(row, vector<int>(col, -1));

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int ans = 0;

    bfs_q.emplace(start_col, start_row);
    visit[start_row][start_col] += 1;

    while (!bfs_q.empty()) {

        auto current = bfs_q.front();
        bfs_q.pop();

        if (current == finish_point)
            break;

        for (int i = 0; i < 4; i++) {

            auto new_pos = current;
            new_pos.first += dx[i];
            new_pos.second += dy[i];

            //새로 가는 곳이 보드 밖으로 안가고, 방문하지 않았
            if (in_boundary(new_pos, i, height, width, row, col)
                && visit[new_pos.second][new_pos.first] == -1
                && !block_exist(new_pos, height, width, i, board)) {
                bfs_q.emplace(new_pos);
                visit[new_pos.second][new_pos.first] = visit[current.second][current.first] + 1;
            }

        }

    }

    cout << visit[finish_point.second][finish_point.first];

    return 0;
}