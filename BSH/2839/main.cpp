#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, 10000);

    dp[3] = 1;
    dp[5] = 1;

    for (int i = 6; i <= N; i++) {
        int temp = min(dp[i - 3], dp[i - 5]);
        if (temp != 10000)
            dp[i] = temp + 1;
    }

    if (dp[N] == 10000)
        cout << "-1";
    else
        cout << dp[N];

    return 0;
}