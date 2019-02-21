#include <iostream>

using namespace std;

int row, col;

void flip(bool board[50][50], bool ans[50][50], int x, int y) {

    for (int new_y = y; new_y < y + 3; new_y++)
        for (int new_x = x; new_x < x + 3; new_x++)
            board[new_y][new_x] = !board[new_y][new_x];

}

int main() {


    cin >> row >> col;

    bool board[50][50];
    bool ans[50][50];
    char a;
    int count = 0;

    for (int y = 0; y < row; y++)
        for (int x = 0; x < col; x++) {
            cin >> a;
            board[y][x] = a - '0';
        }

    for (int y = 0; y < row; y++)
        for (int x = 0; x < col; x++) {
            cin >> a;
            ans[y][x] = a - '0';
        }

    for (int y = 0; y < row - 2; y++)
        for (int x = 0; x < col - 2; x++)
            if (board[y][x] != ans[y][x]) {
                flip(board, ans, x, y);
                count += 1;
            }

    int fail = 0;

    for (int y = 0; y < row; y++)
        for (int x = 0; x < col; x++)
            if (board[y][x] != ans[y][x])
                fail = -1;

    if (fail)
        cout << fail;
    else
        cout << count;


    return 0;
}