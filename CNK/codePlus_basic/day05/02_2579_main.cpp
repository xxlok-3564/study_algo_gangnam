/*
계단 오르기
https://www.acmicpc.net/problem/2579
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int *scores = new int[n + 3];
  int *dp = new int[n + 3];
  scores[0] = 0;
  scores[1] = 0;
  scores[2] = 0;
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 0;

  for (int i = 3; i < n + 3; i++) {
    cin >> scores[i];
  }

  for (int i = 3; i < n + 3; i++) {
    dp[i] = max(scores[i] + dp[i - 2],
                scores[i] + scores[i - 1] + dp[i - 3]);
  }

  cout << dp[n + 2];

  return 0;
}
