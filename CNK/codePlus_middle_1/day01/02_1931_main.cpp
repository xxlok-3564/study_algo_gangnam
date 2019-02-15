/*
회의실 배정
https://www.acmicpc.net/problem/1931
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> a, const pair<int, int> b) {
  if(a.second < b.second) {
    return true;
  } else if(a.second == b.second) {
    if(a.first < b.first) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end(), cmp);
  // for(int i = 0; i < n; i++) {
  //   cout << v[i].first << " " << v[i].second << "\n";
  // }
  
  int tot = 1;
  int endtime = v[0].second;
  for(int i = 1; i < n; i++) {
    if(v[i].first >= endtime) {
      tot += 1;
      endtime = v[i].second;
    }
  }
  cout << tot << '\n';

  return 0;
}
 