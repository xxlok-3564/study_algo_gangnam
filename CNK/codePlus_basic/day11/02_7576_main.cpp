/*
토마토
https://www.acmicpc.net/problem/7576
*/
#include <cstdio>
#include <queue>


using namespace std;

int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int e[1000][1000];
int check[1000][1000];
queue<pair<int, int>> q;

void solve(int n, int m) {
  while (!q.empty()) {
    int node_x = q.front().first;
    int node_y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int tmp_x = node_x + directions[i][0];
      int tmp_y = node_y + directions[i][1];

      if (tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < m &&
          e[tmp_x][tmp_y] == 0) {
        if (check[tmp_x][tmp_y] == 0 ||
            check[tmp_x][tmp_y] > check[node_x][node_y] + 1) {
          check[tmp_x][tmp_y] = check[node_x][node_y] + 1;
          q.push(make_pair(tmp_x, tmp_y));
        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int m, n;  // 가로, 세로
  scanf("%d %d", &m, &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &e[i][j]);
      if(e[i][j] == 1) {
        q.push(make_pair(i, j));
      }
    }
  }

  solve(n, m);

  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (e[i][j] == 0) {
        if (check[i][j] == 0) {
          res = -1;
          break;
        }
        res = max(res, check[i][j]);
      }
    }
    if(res == -1) break;
  }
  printf("%d\n", res);

  return 0;
}
