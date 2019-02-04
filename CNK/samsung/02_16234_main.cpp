/*
인구 이동
https://www.acmicpc.net/problem/16234
*/
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int flag_val[2501];
int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int diff(int num1, int num2) {
  if (num1 > num2)
    return num1 - num2;
  else
    return num2 - num1;
}

void assign_arr(int n, int flag_num, int **arr, int **check) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = flag_val[check[i][j]];
    }
  }
}

int solve(int x, int y, int n, int l, int r, int flag_num, int **arr,
          int **check) {
  stack<pair<int, int>> stk;
  int tot = arr[x][y];
  int cnt = 1;
  check[x][y] = flag_num;
  stk.push(make_pair(x, y));

  while (!stk.empty()) {
    int idx_x = stk.top().first;
    int idx_y = stk.top().second;
    stk.pop();

    for(int i = 0; i < 4; i++) {
      int j = idx_x + directions[i][0];
      int k = idx_y + directions[i][1];
      if(0 <= j && j < n && 0 <= k && k < n && check[j][k] == 0) {
        int diff_num = diff(arr[idx_x][idx_y], arr[j][k]);
        if (diff_num >= l && diff_num <= r) {
          tot += arr[j][k];
          cnt++;
          check[j][k] = flag_num;
          stk.push(make_pair(j, k));
        }
      }
    }    
  }

  return tot / cnt;
}

int main(int argc, char const *argv[]) {
  int n, l, r;
  cin >> n >> l >> r;
  int **arr = new int *[n];
  int **check = new int *[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[n];
    check[i] = new int[n];
    fill_n(check[i], n, 0);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  int flag_num = 0;
  int cnt = 0;
  while (true) {
    flag_num = 0;
    cnt++;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (check[i][j] == 0) {
          flag_num++;
          flag_val[flag_num] = solve(i, j, n, l, r, flag_num, arr, check);
        }
      }
    }

    assign_arr(n, flag_num, arr, check);
    // cout << "cnt :: " << cnt << " flag_num :: " << flag_num << "\n";
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     cout << arr[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
    // cout << "\n";

    if (flag_num == (n * n)) break;    
    for (int i = 0; i < n; i++) {
      fill_n(check[i], n, 0);
    }
  }

  cout << cnt - 1;

  return 0;
}