/*
팩토리얼 0의 개수
https://www.acmicpc.net/problem/1676
*/

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int cnt_2 = 0;
  int cnt_5 = 0;
  for (int i = n; i > 0; i--) {
    // 2의 배수
    if (i % 2 == 0) {
      int num = i;
      while (num % 2 == 0) {
        cnt_2++;
        num /= 2;
      }
    }
    // 5의 배수
    if (i % 5 == 0) {
      int num = i;
      while (num % 5 == 0) {
        cnt_5++;
        num /= 5;
      }
    }
  }

  cout << min(cnt_2, cnt_5) << '\n';

  return 0;
}