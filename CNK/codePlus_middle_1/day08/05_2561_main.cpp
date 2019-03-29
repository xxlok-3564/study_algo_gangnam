/**
 * 놀이 공원
 * https://www.acmicpc.net/problem/1561
 */

#include <iostream>

using namespace std;

int a[10000];
int p, n;

int main() {
  cin >> p >> n;  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  /* 놀이기구 수가 많으면 0분 */
  if (p <= n) {
    cout << p << "\n";
    return 0;
  }

  /*  */
  long long left = 0;
  long long right = 2000000000LL * 10000LL;
  while (left <= right) {
    long long mid = (left + right) / 2;

    /*-
        분 1 2 3 4 5 6 7 8 9
    번호
     1     1 6 7 9 
     2     2   8 
     3     3     10
     4     4
     5     5
            사람     
    */
    /* 어떤 시간(분)에 몇번째 사람부터 몇번째 사람까지 있는지 구하기 */    
    long long begin, end;
    begin = end = 0;
    end = n;
    for (int i = 0; i < n; i++) {
      end += mid / a[i];
    }

    begin = end;
    for (int i = 0; i < n; i++) {
      if (mid % a[i] == 0) {
        begin -= 1;
      }
    }
    begin += 1;

    /* 마지막 사람의 위치에 따라 */
    if (p < begin) {
      right = mid - 1;
    } else if (p > end) {
      left = mid + 1;
    } else {

      /* 해당 시간에서 마지막 사람이 탄 놀이기구 */
      for (int i = 0; i < n; i++) {
        if (mid % a[i] == 0) {
          if (p == begin) {
            cout << i+1 << "\n";
            return 0;
          }
          begin += 1;
        }
      }
    }
  }

  return 0;
}