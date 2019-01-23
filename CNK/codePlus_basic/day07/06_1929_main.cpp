/*
소수 찾기
https://www.acmicpc.net/problem/1929
*/
#include <iostream>
using namespace std;

const int MAX = 1000000;
bool p[MAX + 1];  // true: 지워짐(소수X), false: 지워지지 않음(소수O)

int main() {
  p[0] = p[1] = true;
  for (int i = 2; i * i <= MAX; i++) {
    if (p[i] == false) {
      for (int j = i * 2; j <= MAX; j += i) {
        p[j] = true;
      }
    }
  }

  int m, n;
  cin >> m >> n;
  for (int i = m; i <= n; i++) {
    if (p[i] == false) {
      cout << i << '\n';
    }
  }
  return 0;
}