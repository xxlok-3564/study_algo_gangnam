/**
 * 공유기 설치
 * https://www.acmicpc.net/problem/2110
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool possible(vector<int> &wifi, int C, int x) {
  int cnt = 1;
  int last = wifi[0];

  for (int house : wifi) {
    if (house - last >= x) {
      cnt += 1;
      last = house;
    }
  }

  return cnt >= C;
}

int main() {
  int N, C;
  cin >> N >> C;

  vector<int> wifi(N);
  for (int i = 0; i < N; i++) {
    cin >> wifi[i];
  }

  sort(wifi.begin(), wifi.end());

  /* 인접한 공유기의 거리( 1 ~ 최대 ) */
  int left = 1;
  int right = wifi[N - 1] - wifi[0];

  int ans = left;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (possible(wifi, C, mid)) {
      if (ans < mid) {
        ans = mid;
      }
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << ans << '\n';

  return 0;
}