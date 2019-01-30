/*
좌표 정렬하기2
https://www.acmicpc.net/problem/11651
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].second;
    cin >> v[i].first;
  }

  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i].second << " " << v[i].first << "\n";
  }

  return 0;
}
