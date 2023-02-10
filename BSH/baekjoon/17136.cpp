#include <iostream>
#include <vector>

#define N 10

using namespace std;

int blocks[6];
int ans = 26;

pair<int, int> get_next_pos(pair<int, int> pos) {

    pair<int, int> next_pos = pos;

    next_pos.first += 1;
    if (next_pos.first == N) {
        next_pos.first = 0;
        next_pos.second += 1;
    }

    return next_pos;
}

bool can_put(int def_x, int def_y, vector<vector<bool>> &board, int block_size) {

    for (int y = def_y; y < def_y + block_size; y++) {
        for (int x = def_x; x < def_x + block_size; x++) {
            if (y >= N || x >= N || board[y][x] == 0)
                return false;
        }
    }

    return true;

}

void put_block(int def_x, int def_y, vector<vector<bool>> &board, int block_size, bool type) {

    for (int y = def_y; y < def_y + block_size; y++) {
        for (int x = def_x; x < def_x + block_size; x++) {
            board[y][x] = type;
        }
    }

}

void rec(int x, int y, vector<vector<bool>> &board) {

    pair<int, int> pos = make_pair(x, y);

    while (true) {
        if (pos.second == N || board[pos.second][pos.first] == true)
            break;
        pos = get_next_pos(pos);
    }

    if (pos.second == N) {
        int temp_ans = 0;

        for (int i = 1; i <= 5; i++)
            temp_ans += (5 - blocks[i]);

        if (temp_ans < ans)
            ans = temp_ans;

        return;
    }

    for (int i = 1; i <= 5; i++) {

        if (can_put(pos.first, pos.second, board, i) && blocks[i]) {

            blocks[i] -= 1;
            put_block(pos.first, pos.second, board, i, false);
            rec(pos.first, pos.second, board);
            blocks[i] += 1;
            put_block(pos.first, pos.second, board, i, true);

        }
    }

}


int main() {

    vector<vector<bool>> board(10, vector<bool>(10));

    int getter;
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            cin >> getter;
            board[y][x] = (bool) getter;
        }
    }

    for (int i = 0; i < 6; i++)
        blocks[i] = 5;

    rec(0, 0, board);

    if (ans == 26)
        cout << "-1";
    else
        cout << ans;


}