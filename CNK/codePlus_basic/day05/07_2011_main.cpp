/*
암호 코드
https://www.acmicpc.net/problem/2011
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  int mod = 1000000;
  string password;
  getline(cin, password);

  long long *dp = new long long[password.size()];
  long long cnt = 0;

  for (int i = 0; i < password.size(); i++) {
    dp[i] = 0;
    if (password[i] >= '1' && password[i] <= '9') {  // 1~9;
      dp[i] += i == 0 ? 1 : dp[i - 1];
      dp[i] %= mod;
    }
    if (password[i - 1] == '1' && password[i] >= '0' &&
        password[i] <= '9') {  // 10 ~ 19;
      dp[i] += i - 2 >= 0 ? dp[i - 2] : 1;
      dp[i] %= mod;
    }
    if (password[i - 1] == '2' && password[i] >= '0' &&
        password[i] <= '6') {  // 20 ~ 26;
      dp[i] += i - 2 >= 0 ? dp[i - 2] : 1;
      dp[i] %= mod;
    }
    cnt = dp[i];
  }

  cout << cnt;

  return 0;
}
