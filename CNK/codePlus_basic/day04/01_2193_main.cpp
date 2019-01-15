/*
이친수
https://www.acmicpc.net/problem/2193
*/
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long** dp = new long long*[n + 1];
  for (int i = 0; i <= n; i++) {
    dp[i] = new long long[2];
    fill_n(dp[i], 2, 0);
  }

  dp[1][0] = 0;
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
  }

  cout << dp[n][0] + dp[n][1];

  return 0;
}
