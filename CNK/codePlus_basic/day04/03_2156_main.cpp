/*
포도주 시식
https://www.acmicpc.net/problem/2156
*/

#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  int* yangs = new int[n];
  int** dp = new int*[n];
  fill_n(yangs, n, 0);

  for (int i = 0; i < n; i++) {
    cin >> yangs[i];
    dp[i] = new int[2];  // 마셨을 때, 안 마셨을 때
  }

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      dp[0][0] = yangs[0];
      dp[0][1] = 0;
    } else if (i == 1) {
      dp[1][0] = yangs[0] + yangs[1];
      dp[1][1] = yangs[0];
    } else {
      dp[i][0] =
          max(yangs[i] + yangs[i - 1] + dp[i - 2][1], yangs[i] + dp[i - 1][1]);
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }
  }
  
  cout << max(dp[n-1][0], dp[n-1][1]);
  return 0;
}
