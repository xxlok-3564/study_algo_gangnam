#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int* prices = new int[n + 1];
  int* dp = new int[n + 1];
  fill_n(prices, n + 1, 0);
  fill_n(dp, n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> prices[i];
  }

  for (int i = 1; i <= n; i++) {
    int price = prices[i];

    for (int j = i - 1; j >= i / 2; j--) {
      // price = price < dp[j] + dp[i - j] ? dp[j] + dp[i - j] : price;
      if (price < dp[j] + dp[i - j]) {
        price = dp[j] + dp[i - j];
      }
    }

    dp[i] = price;
  }

  cout << dp[n] << '\n';

  return 0;
}