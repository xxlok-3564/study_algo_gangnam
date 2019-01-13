#include <iostream>

using namespace std;

int main() {
  long long mod = 1000000000;
  int n;
  cin >> n;

  long long** dp = new long long*[n + 1];
  for (int i = 0; i <= n; i++) {
    dp[i] = new long long[10];
    fill_n(dp[i], 10, 0);
  }

  for (int i = 1; i < 10; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 0) {
        dp[i][j] = dp[i - 1][j+1] % mod;
      } else if (j == 9) {
        dp[i][j] = dp[i - 1][j-1] % mod;
      } else {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
      }
    }
  }

  long long tot = 0;
  for (int i = 0; i < 10; i++) {
    tot += dp[n][i];
    tot %= mod; // 더하기 이후에도 나눠줬어야지...ㅠ.ㅠ
  }

  cout << tot << '\n';

  return 0;
}