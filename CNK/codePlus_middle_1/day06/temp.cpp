/*
배열 합치기
https://www.acmicpc.net/problem/11728
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n+m);
  for (int i = 0; i < n+m; i++) {
    scanf("%d", &a[i]);
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < n+m; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
