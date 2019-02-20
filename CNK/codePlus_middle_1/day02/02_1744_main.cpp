/*
수 묶기
https://www.acmicpc.net/problem/1744
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int &a, const int &b) {
  return a > b;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> minus_v;
  vector<int> plus_v;

  int zero_cnt = 0;
  int one_cnt = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if(num < 0) {
      minus_v.push_back(num);
    } else if(num > 1) {
      plus_v.push_back(num);
    } else if(num == 0) {
      zero_cnt++;
    } else {
      one_cnt++;
    }
  }
  sort(minus_v.begin(), minus_v.end());
  sort(plus_v.begin(), plus_v.end(), cmp);

  if(minus_v.size() % 2 == 1) {
    if(zero_cnt > 0) {
      minus_v.push_back(0);
    } else {
      minus_v.push_back(1);
    }
  }
  if(plus_v.size() % 2 == 1) {
    plus_v.push_back(1);
  }
  int tot = one_cnt;
  for(int i = 0; i < minus_v.size(); i+=2) {
    tot += minus_v[i] * minus_v[i+1];
  }
  for(int i = 0; i < plus_v.size(); i+=2) {
    tot += plus_v[i] * plus_v[i+1];
  }

  cout << tot << '\n';

  return 0;
}
