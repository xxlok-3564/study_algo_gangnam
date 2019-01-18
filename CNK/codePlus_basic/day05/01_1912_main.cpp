/*
연속합
https://www.acmicpc.net/problem/1912
*/
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long *dp = new long long[n+1]; // 숫자 범위 잊지마요!
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    long long num;
    cin >> num;
    dp[i] = max(dp[i-1] + num, num);
  }

  long long max = dp[1];  // 0으로 하면 안되요!
  for(int i = 2; i <= n; i++) {
    max = max < dp[i] ? dp[i] : max;
  }
  cout << max;

  return 0;
}