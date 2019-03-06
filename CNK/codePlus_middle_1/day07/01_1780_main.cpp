/*
종이의 개수
https://www.acmicpc.net/problem/1780
*/

#include <iostream>
#include <vector>

using namespace std;

int arr[3] = {
    0,
};

void solve(int s_x, int s_y, int d, vector<vector<int>> &v) {
  // 카드 유무 검사
  bool isCard = true;
  int piv = v[s_x][s_y];
  for (int i = s_x; i < s_x + d; i++) {
    for (int j = s_y; j < s_y + d; j++) {
      if (piv != v[i][j]) {
        isCard = false;
      }
    }
    if (!isCard) break;
  }

  // 카드라면 종료
  if (isCard) {
    arr[1 + piv] += 1;
    // cout << "(" << arr[0] << ", " << arr[1] << ", " << arr[2] << ")";
    // cout << "\n\n";
    return;
  }

  int k = d / 3;

  for (int i = s_x; i < s_x + d; i += k) {
    for (int j = s_y; j < s_y + d; j += k) {
      // cout << "K :: " << k << "\n";
      // cout << "(" << i << ", " << j << ", " << k << ")";
      // cout << "\n";
      solve(i, j, k, v);
    }
  }
  // cout << "\n\n";
}

int main(int argc, char const *argv[]) {
  int n;
  int num;
  cin >> n;
  vector<vector<int>> v(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> num;
      v[i].push_back(num);
    }
  }

  solve(0, 0, n, v);
  for (int i = 0; i < 3; i++) {
    cout << arr[i] << "\n";
  }

  return 0;
}
