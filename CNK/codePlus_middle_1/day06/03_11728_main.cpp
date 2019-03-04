/*
배열 합치기
https://www.acmicpc.net/problem/11728
*/
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n);
  vector<int> b(m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }

  int a_idx = 0;
  int b_idx = 0;
  while(a_idx < n && b_idx < m){
    if(a[a_idx] < b[b_idx]) {
      printf("%d ", a[a_idx]);
      a_idx++;
    } else {
      printf("%d ", b[b_idx]);
      b_idx++;
    }
  }

  for(int i = a_idx; i < n; i++) {
    printf("%d ", a[i]);
  }

  for(int i = b_idx; i < m; i++) {
    printf("%d ", b[i]);
  }

  return 0;
}
