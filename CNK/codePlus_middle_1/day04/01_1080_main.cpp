/*
행렬
https://www.acmicpc.net/problem/1080
*/
#include <cstdio>

using namespace std;

/* 바뀌기 전 행렬 */
int a[50][50];
/* 바뀐 행렬*/
int b[50][50];

void flip(int x, int y) {
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      a[i][j] = 1 - a[i][j];
    }
  }
}

int main() {
  /* 행렬 크기 */
  int n, m;
  scanf("%d %d", &n, &m);

  /* 행렬 입력 받기 */
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &a[i][j]);
    }
  }  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &b[i][j]);
    }
  }

  /* 바꾼 횟수 */
  int ans = 0;

  /* i,j번째의 값이 다르면 3X3크기 행렬만큼 뒤집는다. */
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 2; j++) {
      if (a[i][j] != b[i][j]) {
        ans += 1;
        flip(i + 1, j + 1);
      }
    }
  }

  /* 행렬을 뒤집은 이후 행렬이 제대로 바뀌었는지 검사를 한다. */
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != b[i][j]) {
        printf("-1\n");
        return 0;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}