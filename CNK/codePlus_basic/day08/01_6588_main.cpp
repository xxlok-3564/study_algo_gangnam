/*
골드바흐의 추측
https://www.acmicpc.net/problem/6588
*/
#include <cstdio>

using namespace std;

const int MAX = 1000000;
bool p[MAX + 1];
int arr[MAX + 1];
int arr_index = 0;

int main(int argc, char const *argv[]) {

  p[0] = p[1] = true;  // 소수가 아니다!
  for (int i = 2; i <= MAX; i++) {
    if (p[i] == false) {
      if (i % 2 == 1) arr[arr_index++] = i;
      for (int j = i + i; j <= MAX; j += i) {
        p[j] = true;  // 소수가 아니다!
      }
    }
  }

  while (true) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;

    bool isPossible = false;
    for (int i = 0; i < arr_index; i++) {
      if (arr[i] > n / 2) break;
      if (p[n - arr[i]] == false) {
        isPossible = true;
        printf("%d = %d + %d\n", n, arr[i], n-arr[i]);
        // cout << n << " = " << arr[i] << " + " << n - arr[i] << "\n";
        break;
      }
    }
    if (isPossible == false) printf("Goldbach's conjecture is wrong.\n");
  }
  return 0;
}
