/*
병든 나이트
https://www.acmicpc.net/problem/1783
*/
#include <iostream>
#include <queue>

using namespace std;

bool check[4] = {
    false,
};

int main(int argc, char const *argv[]) {
  int n, m;  // 세로, 가로
  cin >> n >> m;
  int x = 1;
  int y = m;
  int cnt = 1;

  if (n == 1 || m == 1) {
    cnt = 1;
  } else if (n == 2) {
    if(m < 3) {
      cnt = 1;
    } else if(m < 5) {
      cnt += 1;
    } else if(m < 7) {
      cnt += 2;
    } else {
      cnt += 3;
    }
  } else {
    if (m < 7) {
      if (m <= 4) {
        cnt += m - 1;
      } else {
        cnt += 3;
      }
    } else {
      cnt += 4;
    }
  }
  
  if (n >= 3 && m > 7) {
    cnt += m - 7;
  }

  cout << cnt;

  return 0;
}
