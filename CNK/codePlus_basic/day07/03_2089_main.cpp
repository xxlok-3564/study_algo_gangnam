/*
-2진수
https://www.acmicpc.net/problem/2089
*/

#include <iostream>

using namespace std;

void solve(int n) {
  if (n == 0) {
    return;
  }
  if (n % 2 == 0) {
    // 짝수
    solve(-(n / 2));
    cout << "0";
  } else {
    if (n > 0) {  // 양수홀수
      solve(-(n / 2));
    } else {  // 음수홀수
      solve(-(n - 1) / 2);
    }
    cout << "1";
  }
}
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  if (n == 0) {
    cout << "0";
  } else {
    solve(n);
  }
  return 0;
}