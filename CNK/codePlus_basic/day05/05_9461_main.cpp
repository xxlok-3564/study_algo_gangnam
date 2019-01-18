/*
파도반 수열
https://www.acmicpc.net/problem/9461
*/
#include <iostream>

using namespace std;

int main() {
  long long **dp = new long long*[101];
  for(int i = 0; i <= 100; i++) {
    dp[i] = new long long[2];
  }
  dp[0][0] = 0;  dp[0][1] = 1;  // X
  dp[1][0] = 1;  dp[1][1] = 2;  // O
  dp[2][0] = 1;  dp[2][1] = 1;  // X
  dp[3][0] = 1;  dp[3][1] = 2;  // O

  int a = 0;
  int b = 1;
  for (int i = 4; i <= 100; i++) {
    dp[i][1] = 2;

    if (i % 2 == 0) {  // X
      dp[i][0] = dp[b][0]+dp[i - 1][0];
      dp[i-1][1]--;
      dp[b][1]--;
      if (dp[b][1] == 0) b += 2;
    } else {  // O
      dp[i][0] = dp[a][0]+dp[i - 1][0];
      dp[i-1][1]--;
      dp[a][1]--;
      if (dp[a][1] == 0) a += 2;
    }
  }

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    cout << dp[n][0] << '\n';
  }

  return 0;
}