/*
진법 변환
https://www.acmicpc.net/problem/2745
*/

#include <iostream>

using namespace std;

long long solve(string numbers, int b) {
  long long res = 0;
  long long jari = 1;

  for (int i = numbers.size() - 1; i >= 0; i--) {
    char c = numbers[i];
    if (c >= '0' && c <= '9') {
      c = c - '0';
      res += c * jari;
    } else {
      c = 10 + (c - 'A');
      res += c * jari;
    }
    jari *= b;
  }

  return res;
}

int main(int argc, char const *argv[]) {
  string numbers;
  int b;
  cin >> numbers >> b;

  cout << solve(numbers, b);

  return 0;
}
