/**
 * 리모컨
 * https://www.acmicpc.net/problem/1107
 */

#include <iostream>
#include <vector>

using namespace std;

int checkPush(int num, vector<int> number) {
  /* 0번 채널도 한번 누르는거야... */
  if (num == 0) {
    if (number[0] == -1) {
      return 0;
    } else {
      return 1;
    }
  }

  int cnt = 0;
  while (num > 0) {
    int k = num % 10;
    if (number[k] == -1) {
      return 0;
    }
    num /= 10;
    cnt++;
  }
  return cnt;
}

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> number(10);
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    number[num] = -1;
  }
  int ans;

  /* 현재 채널이 100이면 0 */
  int nowChanel = 100;
  if (n == nowChanel) {
    cout << 0 << "\n";
    return 0;
  }

  /* 가장 무식한 방법 */
  int maxPush = nowChanel - n;
  if (maxPush < 0) {
    maxPush = -maxPush;
  }
  ans = maxPush;

  /* 왼쪽 오른쪽 비교 */
  int left = n;
  int right = n + 1;
  int cnt = 0;
  while (left >= 0 || cnt < maxPush) {
    if (checkPush(left, number) > 0) {
      if (ans > (checkPush(left, number) + (n - left))) {
        ans = (checkPush(left, number) + (n - left));
      }
      break;
    }
    left--;
    cnt++;
  }

  cnt = 1;
  while (cnt < maxPush) {
    if (checkPush(right, number) > 0) {
      if (ans > (checkPush(right, number) + (right - n))) {
        ans = (checkPush(right, number) + (right - n));
      }
      break;
    }
    right++;
    cnt++;
  }

  cout << ans << "\n";

  return 0;
}
