/*
합분해
https://www.acmicpc.net/problem/2225
*/

#include <iostream>
using namespace std;
// long long d[201][201];
long long d[201];
long long mod = 1000000000;
int main() {
  int n, k;
  cin >> n >> k;

  // d[0][0] = 1LL;
  // d[갯수][끝숫자];
  // for (int i = 1; i <= k; i++) {
  //   for (int j = 0; j <= n; j++) {
  //     for (int l = 0; l <= j; l++) {
  //       d[i][j] += d[i - 1][j - l];
  //       d[i][j] %= mod;
  //     }

  //     for (int l = 0; l <= n; l++) {
  //       printf("%3d ", d[i][l]);
  //     }
  //     printf("\n");
  //   }
  //   printf("\n");
  // }

  // cout << d[k][n] << '\n';

  // 1차원 배열로 푸는 방법
  d[0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = n; j >= 0; j--) {
      for (int l = 1; l <= j; l++) {
        d[j] += d[j - l];
        d[j] %= mod;
      }

      for (int l = 0; l <= n; l++) {
        printf("%3d ", d[l]);
      }
      printf("\n");
    }
    printf("\n");
  }
  cout << d[n];

  return 0;
}