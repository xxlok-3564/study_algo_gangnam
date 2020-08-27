#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int board_size, command_size;

    cin >> board_size >> command_size;

    vector<vector<int>> board(board_size + 1, vector<int>(board_size + 1, 0));
    vector<vector<long long>> dp(board_size + 1, vector<long long>(board_size + 1, 0));

    for (int y = 1; y <= board_size; y++) {
        for (int x = 1; x <= board_size; x++) {
            cin >> board[y][x];
            if (x == 1 && y == 1) {
                dp[y][x] = board[y][x];
            } else if (x == 1) {
                dp[y][x] = dp[y - 1][x] + board[y][x];
            } else if (y == 1) {
                dp[y][x] = dp[y][x - 1] + board[y][x];
            } else {
                dp[y][x] = dp[y - 1][x] + dp[y][x - 1] - dp[y - 1][x - 1] + board[y][x];
            }
        }
    }


    for (int command = 0; command < command_size; command++) {

        int x1, x2, y1, y2;

        cin >> y1 >> x1 >> y2 >> x2;

        cout << dp[y2][x2] + dp[y1 - 1][x1 - 1] - dp[y2][x1 - 1] - dp[y1 - 1][x2] << '\n';

    }

    return 0;
}