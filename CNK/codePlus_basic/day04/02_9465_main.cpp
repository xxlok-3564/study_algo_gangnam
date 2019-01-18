/*
스티커
https://www.acmicpc.net/problem/9465
*/
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int** scores = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
      scores[i] = new int[2];
    }
    for (int i = 1; i <= n; i++) {
      cin >> scores[i][0];
    }
    for (int i = 1; i <= n; i++) {
      cin >> scores[i][1];
    }

    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
      dp[i] = new int[3];  // 0번째 떼기, 1번째 떼기, 모두 안 떼기
      fill_n(dp[i], 3, 0);
    }

    for (int i = 1; i <= n; i++) {
      dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + scores[i][0];
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + scores[i][1];
      dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
    }

    // for (int i = 0; i < 3; i++) {
    //   for (int j = 0; j <= n; j++) {
    //     cout << dp[j][i] << ' ';
    //   }
    //   cout << '\n';
    // }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
  }

  return 0;
}
