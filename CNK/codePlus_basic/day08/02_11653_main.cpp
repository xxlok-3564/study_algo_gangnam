/*
소인수분해
https://www.acmicpc.net/problem/11653
*/

#include <iostream>

using namespace std;

const int MAX = 10000000;
bool p[MAX + 1];
int arr[MAX + 1];
int arr_idx = 0;

int main(int argc, char const *argv[]) {
  p[0] = p[1] = true;  // 소수가 아니다!
  for (int i = 2; i <= MAX; i++) {
    if (p[i] == false) {
      arr[arr_idx++] = i;
      for (int j = i + i; j <= MAX; j += i) {
        p[j] = true;  // 소수가 아니다!
      }
    }
  }

  int n;
  cin >> n;
  int idx = 0;
  while (n > 1) {
    if (n % arr[idx] == 0) {      
      cout << arr[idx] << '\n';
      n /= arr[idx];
    } else {
      idx++;
    }
  }

  return 0;
}
