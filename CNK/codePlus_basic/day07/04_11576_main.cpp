/*
Base Conversion
https://www.acmicpc.net/problem/11576
*/

#include <math.h>
#include <iostream>
using namespace std;

int baseConversion(int n, int b, int *arr) {
  int i = 0;
  while (n > 0) {
    arr[i++] = n % b;
    n = n / b;
  }
  return i;
}

int main() {
  int a, b;  // a진법 -> b진법
  cin >> a >> b;
  int m;  // 길이
  cin >> m;

  int n = 0;  // 10진법으로 변환값
  for (int i = 1; i <= m; i++) {
    int temp;
    cin >> temp;
    n += temp * pow(a, m - i);
  }

  int *arr = new int[21];  // 몇개의 자리로 구성될지 모른다.
  int len = baseConversion(n, b, arr);
  for (int i = len - 1; i > 0; i--) {
    cout << arr[i] << " ";
  }
  cout << arr[0] << endl;

  return 0;
}