/*
팩토리얼
https://www.acmicpc.net/problem/10872
*/

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long fact = 1;
  for(int i = n; i > 0; i--) {
    fact *= i;
  }

  cout << fact << '\n';

  return 0;
}