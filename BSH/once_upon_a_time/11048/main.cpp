#include <iostream>
#include <vector>

using namespace std;

int row, col;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col;

    vector<vector<int>> board(row, vector<int>(col, 0));
    vector<vector<int>> dp(row, vector<int>(col, 0));

    for (int y = 0; y < row; y++)
        for (int x = 0; x < col; x++)
            cin >> board[y][x];

    dp[0][0] = board[0][0];

    for (int y = 1; y < row; y++)
        dp[y][0] = dp[y - 1][0] + board[y][0];

    for (int x = 1; x < col; x++)
        dp[0][x] = dp[0][x - 1] + board[0][x];

    for (int y = 1; y < row; y++)
        for (int x = 1; x < col; x++)
            dp[y][x] = max(max(dp[y - 1][x], dp[y][x - 1]), dp[y - 1][x - 1]) + board[y][x];

    cout << dp[row - 1][col - 1];

    return 0;
}




/*int get_cost(int x, int y, int dir, vector<vector<int>> &board, vector<vector<vector<int>>> &dp) {

    if (!(0 <= x && x < col && 0 <= y && y < row))
        return 0;

    if (dp[y][x][dir] != -1)
        return dp[y][x][dir];

    int val = 0;
    int prev_x;
    int prev_y;
    switch (dir) {
        case 0:
            prev_x = x - 1;
            prev_y = y;
            break;
        case 1:
            prev_x = x;
            prev_y = y - 1;
            break;

        case 2:
            prev_x = x - 1;
            prev_y = y - 1;
            break;
    }

    for (int i = 0; i < 3; i++) {
        int temp = get_cost(prev_x, prev_y, i, board, dp);
        if (temp > val) val = temp;
    }

    return dp[y][x][dir] = val + board[y][x];


}

int main() {

    cin >> row >> col;

    vector<vector<int>> board(row, vector<int>(col, 0));
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(3, -1)));

    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            cin >> board[y][x];
        }
    }

    dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = board[0][0];

    cout << max(max(get_cost(col - 1, row - 1, 0, board, dp),
                    get_cost(col - 1, row - 1, 1, board, dp)),
                get_cost(col - 1, row - 1, 2, board, dp));


    return 0;
}*/