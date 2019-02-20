/*
30
https://www.acmicpc.net/problem/10610
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(const int &a, const int &b) { return a > b; }

int main(int argc, char const *argv[]) {
  // 범위크기를 잘보자...
  // 문자열을 sort해서
  // reverse를 이용해서 풀어도 가능!
  string num;
  vector<int> v;
  int zero_cnt = 0;
  int hab = 0;
  
  cin >> num;
  for(int i = 0; i < num.size(); i++) {
    hab += num[i] - '0';
    v.push_back(num[i]-'0');
  }

  sort(v.begin(), v.end(), cmp);
  if (hab % 3 == 0 && v[v.size()-1] == 0) {        
    for (int i = 0; i < v.size(); i++) {
      cout << v[i];
    }
    cout << "\n";
  } else {
    cout << -1 << '\n';
  }  

  return 0;
}
