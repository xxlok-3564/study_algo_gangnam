#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int ans = numeric_limits<int>::max();

int main() {

    int N;
    cin >> N;

    vector<int> combination(N);

    for (int i = 0; i < N; i++)
        combination[i] = i;

    vector<vector<int>> board(N, vector<int>(N));
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];

    do {

        bool fail = false;
        int cost = 0;
        for (int i = 0; i < combination.size() - 1; i++) {
            if (board[combination[i]][combination[i + 1]]) {

                cost += board[combination[i]][combination[i + 1]];

            } else {
                fail = true;
                break;
            }
        }

        if (board[combination[combination.size() - 1]][combination[0]])
            cost += board[combination[combination.size() - 1]][combination[0]];
        else
            fail = true;

        if (!fail)
            if (cost < ans) ans = cost;

    } while (next_permutation(combination.begin(), combination.end()));

    cout << ans;

    return 0;
}