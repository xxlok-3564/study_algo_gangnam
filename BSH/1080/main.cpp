#include <iostream>

using namespace std;

int main() {

    int row, col;
    cin >> row >> col;

    bool board[row][col];
    bool ans[row][col];

    for (int y = 0; y < row; y++)
        for (int x = 0; x < col; x++)
            cin >> board[y][x];

    for (int y = 0; y < row; y++)
        for (int x = 0; x < col; x++)
            cin >> ans[y][x];

    return 0;
}