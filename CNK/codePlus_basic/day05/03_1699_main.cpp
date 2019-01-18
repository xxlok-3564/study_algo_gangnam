/*
제곱수의 합
https://www.acmicpc.net/problem/1699
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  int *dp = new int[n + 1];
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = i;    
    for (int j = 1; j * j <= i; j++) {
      if(j*j == i) dp[i] = 1;
      // dp[j*j]는 항상 1 이다! 1로 바꿔도 된다!
      if (dp[i] > dp[i - (j * j)] + dp[j * j]) {
        dp[i] = dp[i - (j * j)] + dp[j * j];
      }
    }    
  }

  cout << dp[n];

  return 0;
}