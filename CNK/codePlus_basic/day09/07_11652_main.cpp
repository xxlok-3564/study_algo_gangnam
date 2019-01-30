/*
카드
https://www.acmicpc.net/problem/11652
*/
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  map<long long, int> m;

  long long sel_num;
  int cnt;
  
  cin >> sel_num;  
  m[sel_num] = cnt = 1;

  for (int i = 1; i < n; i++) {
    long long num;
    cin >> num;
    if (m.find(num) != m.end()) {
      m[num]++;
    } else {
      m[num] = 1;
    }
    if(cnt < m[num]) {
      sel_num = num;
      cnt = m[num];
    } else if(cnt == m[num] && sel_num > num) {
      sel_num = num;
    }
  }

  cout << sel_num << "\n";

  return 0;
}
