#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int* dp = new int[n + 1];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i-1] + dp[i-2]) % 10007;

    // 바보... 더하면 10007이 넘을수도 있자나...
    // dp[i] = 0;

    // if (i - 1 > 0) {
    //   dp[i] += dp[i - 1] % 10007;
    // }
    // if (i - 2 > 0) {
    //   dp[i] += dp[i - 2] % 10007;
    // }
  }
  cout << dp[n] << '\n';

  return 0;
}