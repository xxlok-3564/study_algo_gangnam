#include <iostream>
#include <vector>

using namespace std;


int main() {
    int row;
    int col;
    int time;

    cin >> row >> col;
    cin >> time;

    vector<vector<int>> board(row, vector<int>(col));
    int linear[min(row, col) / 2][2 * (row - 1) + 2 * (col - 1)];

    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {

            cin >> board[y][x];
            int layer = min(min(x, y), min(row - y - 1, col - x - 1));
            int num_block = 2 * (row - 1 - 2 * layer) + 2 * (col - 1 - 2 * layer);

            if (y - layer == 0) {
                linear[layer][x + y - 2 * layer] = board[y][x];
            } else if (x - layer == col - 1 - (2 * layer)) {
                linear[layer][x + y - 2 * layer] = board[y][x];
            } else if (x - layer == 0) {
                linear[layer][num_block - (x + y - 2 * layer)] = board[y][x];
            } else if (y - layer == row - 1 - (2 * layer)) {
                linear[layer][num_block - (x + y - 2 * layer)] = board[y][x];
            }

        }
    }


    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {

            int layer = min(min(x, y), min(row - y - 1, col - x - 1));
            int num_block = 2 * (row - 1 - layer * 2) + 2 * (col - 1 - layer * 2);

            if (y - layer == 0) {
                cout << linear[layer][((x + y - 2 * layer) + time) % num_block] << " ";
            } else if (x - layer == col - 1 - (2 * layer)) {
                cout << linear[layer][((x + y - 2 * layer) + time) % num_block] << " ";
            } else if (x - layer == 0) {
                cout << linear[layer][(num_block - (x + y - 2 * layer) + time) % num_block] << " ";
            } else if (y - layer == row - 1 - (2 * layer)) {
                cout << linear[layer][(num_block - (x + y - 2 * layer) + time) % num_block] << " ";
            }

        }
        cout << '\n';
    }

    return 0;
}