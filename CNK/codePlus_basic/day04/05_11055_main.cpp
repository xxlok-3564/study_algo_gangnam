/*
가장 큰 증가 부분 수열
https://www.acmicpc.net/problem/11053
*/

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int *pmt = new int[n];
  int *dp = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> pmt[i];
  }

  int max = pmt[0];
  dp[0] = pmt[0];
  for (int i = 1; i < n; i++) {
    dp[i] = pmt[i];
    for (int j = i - 1; j >= 0; j--) {
      if (pmt[i] > pmt[j] && dp[i] < dp[j] + pmt[i]) {
        dp[i] = dp[j] + pmt[i];
      }
    }
    if (dp[i] > max) max = dp[i];
  }

  cout << max << '\n';

  return 0;
}