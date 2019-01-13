#include <iostream>

using namespace std;

int main() {
  int n;
  int mod = 10007;
  cin >> n;

  int** dp = new int*[n+1];
  for(int i = 0; i <= n; i++) {
    dp[i] = new int[10];
    fill_n(dp[i], 10, 1); // dp[1][i]를 모두 1로 초기화
  }

  for(int i = 2; i <= n; i++) {
    for(int j = 0; j < 10; j++) {
      dp[i][j] = 0;
      for(int k = 0; k <= j; k++) {
        dp[i][j] += dp[i-1][k];
        dp[i][j] %= mod;
      }
    }
  }

  int tot = 0;
  for(int i = 0; i < 10; i++) {
    tot += dp[n][i];
    tot %= mod;
  }
  cout << tot << '\n';

  return 0;
}