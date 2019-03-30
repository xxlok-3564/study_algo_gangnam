#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <set>

using namespace std;

int ans = numeric_limits<int>::max();

bool can_put(vector<pair<int, int>> &three_pos) {

    set<pair<int, int>> a;

    vector<int> dy = {0, 0, 0, -1, 1};
    vector<int> dx = {0, 1, -1, 0, 0};

    for (pair<int, int> pos : three_pos)
        for (int i = 0; i < 5; i++)
            a.insert({pos.first + dx[i], pos.second + dy[i]});

    return a.size() == 15;
}

int get_cost(vector<vector<int>> &board, pair<int, int> pos) {
    int n = 0;

    vector<int> dy = {0, 0, 0, -1, 1};
    vector<int> dx = {0, 1, -1, 0, 0};

    for (int i = 0; i < 5; i++)
        n += board[pos.second + dy[i]][pos.first + dx[i]];

    return n;
}

int main() {

    int N;

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    vector<vector<int>> cost_board(N, vector<int>(N));

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];

    for (int y = 1; y < N - 1; y++)
        for (int x = 1; x < N - 1; x++)
            cost_board[y][x] = get_cost(board, {x, y});


    vector<bool> comb((N - 2) * (N - 2), false);

    fill(comb.end() - 3, comb.end(), true);

    do {

        vector<pair<int, int>> three_pos;
        for (int i = 0; i < comb.size(); i++)
            if (comb[i]) three_pos.emplace_back(1 + (i % (N - 2)), 1 + (i / (N - 2)));

        if (can_put(three_pos)) {

            int temp = 0;

            for (pair<int, int> pos : three_pos)
                temp += cost_board[pos.second][pos.first];

            if (temp < ans)
                ans = temp;
        }


    } while (next_permutation(comb.begin(), comb.end()));

    cout << ans;

    return 0;
}