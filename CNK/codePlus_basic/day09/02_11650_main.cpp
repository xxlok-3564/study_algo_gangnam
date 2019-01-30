/*
좌표 정렬하기
https://www.acmicpc.net/problem/11650
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
    cin >> v[i].first;
    cin >> v[i].second;
  }

  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i].first << " " << v[i].second << "\n";
  }

  return 0;
}
