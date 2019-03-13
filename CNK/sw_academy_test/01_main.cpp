#include <iostream>
#include <vector>

using namespace std;

int cnt;
// 오른쪽[0], 아래쪽[1], 대각선[2]
int dir_1[3][3][2] = {
    {{0, 1}, {1, 1}, {0, 0}},  // 오른쪽, 대각선, 의미X
    {{1, 0}, {1, 1}, {0, 0}},  // 아래쪽, 대각선, 의미X
    {{0, 1}, {1, 0}, {1, 1}}   // 오른쪽, 아래쪽, 대각선
};

int dir_2[3][3][1] = {
    {{0}, {2}, {-1}},  // 오른쪽, 대각선, 의미X
    {{1}, {2}, {-1}},  // 아래쪽, 대각선, 의미X
    {{0}, {1}, {2}}    // 오른쪽, 아래쪽, 대각선
};

void print_root(vector<vector<int>> &check, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << check[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n\n";
}

void solve(int x, int y, int n, int direction, vector<vector<int>> &map,
           vector<vector<int>> &check) {
  // 해당되지 않으면 return
  if (map[x][y] == 1 || check[x][y] == 1) {
    return;
  }

  check[x][y] = 1;
  // 오른쪽이나 아래방향으로
  // 도착지에 도착하면 cnt+=1
  if (x == n - 1 && y == n - 1 && direction < 2) {
    cnt += 1;
    check[x][y] = 0;
    return;
  }

  for (int i = 0; i < 3; i++) {
    int next_x = x + dir_1[direction][i][0];
    int next_y = y + dir_1[direction][i][1];

    if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n &&
        map[next_x][next_y] == 0) {
      if (dir_2[direction][i][0] == 2) {
        // 대각선일 경우...
        if (map[x][y + 1] == 0 && map[x + 1][y] == 0) {
          // check[next_x][next_y] = 1;
          solve(next_x, next_y, n, dir_2[direction][i][0], map, check);
          // check[next_x][next_y] = 0;
        }
      } else if (dir_2[direction][i][0] != -1) {
        // 대각선이 아닐 경우...
        // check[next_x][next_y] = 1;
        solve(next_x, next_y, n, dir_2[direction][i][0], map, check);
        // check[next_x][next_y] = 0;
      }
    }
  }
  check[x][y] = 0;
}

int main(int argc, char const *argv[]) {
  int t, n, num;
  cin >> t;
  for (int test_num = 1; test_num <= t; test_num++) {
    cin >> n;
    vector<vector<int>> map(n);
    vector<vector<int>> check(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> num;
        map[i].push_back(num);
        check[i].push_back(0);
      }
    }

    cnt = 0;
    solve(0, 1, n, 0, map, check);
    solve(1, 0, n, 1, map, check);

    cout << cnt << "\n";
  }

  return 0;
}
