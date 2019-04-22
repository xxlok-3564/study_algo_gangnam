#include <iostream>
#include <vector>

using namespace std;


int rec(int N, int K, vector<vector<int>> &dp) {


    if (dp[N][K] != -1)
        return dp[N][K];
    else {

        if (N == K || K == 0)
            return dp[N][K] = 1;
        else
            return dp[N][K] = rec(N - 1, K, dp) + rec(N - 1, K - 1, dp);
    }
}

int main() {

    int N, K;

    cin >> N >> K;

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

    cout << rec(N, K, dp);

    return 0;
}