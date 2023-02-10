#include <iostream>

using namespace std;

long long get_cost(int x, int y, int type, int board[33][33],
                   long long dp_memo[33][33][3], int &N) {

    if (0 <= x && x < N && 0 <= y && y < N) {
        if (dp_memo[y][x][type] != -1)
            return dp_memo[y][x][type];

        switch (type) {
            case 0:
                if (board[y][x] == 1)
                    dp_memo[y][x][type] = 0;
                else
                    dp_memo[y][x][type] =
                            get_cost(x - 1, y, 0, board, dp_memo, N) + get_cost(x - 1, y, 2, board, dp_memo, N);
                break;

            case 1:
                if (board[y][x] == 1)
                    dp_memo[y][x][type] = 0;
                else
                    dp_memo[y][x][type] =
                            get_cost(x, y - 1, 1, board, dp_memo, N) + get_cost(x, y - 1, 2, board, dp_memo, N);
                break;

            case 2:
                if ((board[y][x] == 1) || (board[y - 1][x] == 1) || (board[y][x - 1] == 1))
                    dp_memo[y][x][type] = 0;
                else
                    dp_memo[y][x][type] = get_cost(x - 1, y - 1, 0, board, dp_memo, N)
                                          + get_cost(x - 1, y - 1, 1, board, dp_memo, N)
                                          + get_cost(x - 1, y - 1, 2, board, dp_memo, N);
                break;

        }

        return dp_memo[y][x][type];

    } else

        return 0;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int board[33][33];
    long long dp_memo[33][33][3];

    int N;
    cin >> N;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> board[y][x];
            for (int thr = 0; thr < 3; thr++)
                dp_memo[y][x][thr] = -1;
        }
    }

    dp_memo[0][1][0] = 1;

    cout << get_cost(N - 1, N - 1, 0, board, dp_memo, N) + get_cost(N - 1, N - 1, 1, board, dp_memo, N) +
            get_cost(N - 1, N - 1, 2, board, dp_memo, N);


    return 0;
}