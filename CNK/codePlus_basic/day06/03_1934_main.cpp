/*
최소공배수
https://www.acmicpc.net/problem/1934
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int T;
  int a, b;
  cin >> T;
  while (T--) {
    cin >> a >> b;
    int m = 2;
    int gcd = 1;

    while (1) {
      if (m > a || m > b) {
        break;
      }

      if (a % m == 0 && b % m == 0) {
        a /= m;
        b /= m;
        gcd *= m;
        m = 2;
      } else {
        m++;
      }
    }
    cout << gcd * a * b << '\n';
  }

  return 0;
}
