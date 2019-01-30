/*
수 정렬하기2
https://www.acmicpc.net/problem/2751
cf) https://www.acmicpc.net/blog/view/22
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());  

  for (int i = 0; i < n; i++) {
    cout << v[i] << '\n';
  }

  return 0;
}
