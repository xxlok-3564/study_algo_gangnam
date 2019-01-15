/*
가장 긴 증가하는 부분 수열
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

  int max = 1;
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (pmt[i] > pmt[j] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }
    if (dp[i] > max) max = dp[i];
  }

  cout << max;

  return 0;
}