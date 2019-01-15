/*
가장 긴 바이토닉 부분 수열
https://www.acmicpc.net/problem/11054
*/

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int *pmt = new int[n];
  int **dp = new int *[n];
  for (int i = 0; i < n; i++) {
    cin >> pmt[i];
    dp[i] = new int[2];
  }

  for (int i = 0; i < n; i++) {
    dp[i][0] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (pmt[i] > pmt[j] && dp[i][0] < dp[j][0] + 1) {
        dp[i][0] = dp[j][0] + 1;
      }
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    dp[i][1] = 1;
    for (int j = i + 1; j < n; j++) {
      if (pmt[i] > pmt[j] && dp[i][1] < dp[j][1] + 1) {
        dp[i][1] = dp[j][1] + 1;
      }
    }
  }

  int max = 0;
  for (int i = 0; i < n; i++) {
    if (max < dp[i][0] + dp[i][1] - 1) max = dp[i][0] + dp[i][1] - 1;
  }

  cout << max << '\n';

  return 0;
}