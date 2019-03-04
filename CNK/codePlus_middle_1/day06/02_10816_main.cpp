/*
숫자 카드2
https://www.acmicpc.net/problem/10816
*/
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int search(int num, vector<pair<int, int>> &a) {
  int left = 0;
  int right = a.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (a[mid].first == num) {
      return a[mid].second;
    } else if (a[mid].first > num) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return 0;
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());

  // 중복되는 숫자 제거 및 빈도수 저장
  // first = num, second = frequency
  vector<pair<int, int>> vv;
  vv.push_back(make_pair(a[0], 1));
  int idx = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == vv[idx].first) {
      vv[idx].second++;
    } else {
      vv.push_back(make_pair(a[i], 1));
      idx++;
    }
  }

  int m;
  int num;
  scanf("%d", &m);
  
  for (int i = 0; i < m; i++) {
    scanf("%d", &num);
    printf("%d ", search(num, vv));
  }
  printf("\n");

  return 0;
}