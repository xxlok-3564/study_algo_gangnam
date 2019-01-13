#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int* dp = new int[n + 1];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 3;

  for (int i = 3; i <= n; i++) {
    dp[i] = ((dp[i-2]*2)+dp[i-1]) % 10007;
  }

  cout << dp[n] << '\n';

  return 0;
}