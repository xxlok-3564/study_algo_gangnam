/*
숫자 카드
https://www.acmicpc.net/problem/10815
*/
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int search(int num, vector<int> &a, int _size) {
  int left = 0;
  int right = _size - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    if (a[mid] == num) {
      return mid;
    } else if (a[mid] > num) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);    
  }
  sort(a.begin(), a.end());

  int m;
  int num;
  int res;
  scanf("%d", &m);
  for (int i = 0; i < m - 1; i++) {    
    scanf("%d", &num);
    res = search(num, a, n);
    if (res != -1) {
      printf("1");
    } else {
      printf("0");
    }
    printf(" ");
  }  
  scanf("%d", &num);
  res = search(num, a, n);
  if (res != -1) {
    printf("1");
  } else {
    printf("0");
  }

  return 0;
}