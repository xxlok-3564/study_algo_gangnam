/*
대회 or 인턴
https://www.acmicpc.net/problem/2875
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, m, k;
  cin >> n >> m >> k;

  int pos_n = n/2;
  int pos_m = m;
  int pos_team = 0;
  if(pos_n < pos_m) pos_team = pos_n;
  else pos_team = pos_m;

  int r_n = n - (pos_team * 2);
  int r_m = m - pos_team;

  int r = r_n + r_m;

  int ans;
  if(r > k) {
    ans = pos_team;
  } else {
    r = k - r;
    int del_team = r/3;
    if(r%3 > 0) del_team++;
    ans = pos_team - del_team;
  }

  cout << ans;
  
  return 0;
}
