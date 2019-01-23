/*
소수 찾기
https://www.acmicpc.net/problem/1978
*/
#include <iostream>
using namespace std;

int main() {
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (num == 1) continue;
    int g;
    for (int i = 1; i <= num / 2; i++)
      if (num % i == 0) {
        g = i;
      }
    if (g == 1) {
      cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}