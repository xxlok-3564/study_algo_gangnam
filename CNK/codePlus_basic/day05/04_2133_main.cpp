/*
타일 채우기
https://www.acmicpc.net/problem/2133
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int *dp = new int[n + 1];
  dp[0] = 1;  // 곱하기를 하기때문에 1로 초기화
  for (int i = 2; i <= n; i += 2) {
    // dp[i] = 0;
    // dp[i] = 3 * dp[i - 2] + 2 * dp[i - 4];  // 2칸있을때, 4칸있을때

    dp[i] = 0;
    dp[i] += 3*dp[i-2];
    for (int j = i - 4; j >= 0; j -= 2) {
      dp[i] += 2*dp[j];
    }
  }

  cout << dp[n];

  return 0;
}
