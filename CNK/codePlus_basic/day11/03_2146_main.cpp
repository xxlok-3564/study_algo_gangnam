/*
다리 만들기
https://www.acmicpc.net/problem/2146
*/
#include <cstdio>
#include <queue>

using namespace std;

int e[100][100];
int check[100][100];
int group[100][100];
queue<pair<int, int>> q_1;
int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void group_init(int x, int y, int group_num, int n) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  group[x][y] = group_num;

  while (!q.empty()) {
    int node_x = q.front().first;
    int node_y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int tmp_x = node_x + directions[i][0];
      int tmp_y = node_y + directions[i][1];

      if (tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < n) {
        if (e[tmp_x][tmp_y] == 1 && group[tmp_x][tmp_y] == 0) {
          q.push(make_pair(tmp_x, tmp_y));
          group[tmp_x][tmp_y] = group_num;
        }
      }
    }
  }
}

int solve(int n) {
  while (!q_1.empty()) {
    int node_x = q_1.front().first;
    int node_y = q_1.front().second;
    q_1.pop();

    for (int i = 0; i < 4; i++) {
      int tmp_x = node_x + directions[i][0];
      int tmp_y = node_y + directions[i][1];

      if (tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < n) {
        if (e[tmp_x][tmp_y] == 0 &&
            (group[tmp_x][tmp_y] == 0 ||
             check[tmp_x][tmp_y] > check[node_x][node_y] + 1)) {
          q_1.push(make_pair(tmp_x, tmp_y));
          group[tmp_x][tmp_y] = group[node_x][node_y];
          check[tmp_x][tmp_y] = check[node_x][node_y] + 1;
        }
      }
    }
  }

  int res = 100000;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {      
      for (int k = 0; k < 4; k++) {
        int tmp_x = i + directions[k][0];
        int tmp_y = j + directions[k][1];

        if (tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < n) {
          if (group[i][j] != group[tmp_x][tmp_y]) {
            res = min(res, check[i][j] + check[tmp_x][tmp_y]);  // 오타... group으로... 바보... 복사하면 맨날 이러네 ㅠㅠ
          }
        }
      }
    }
  }

  return res;
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &e[i][j]);
      if (e[i][j] == 1) q_1.push(make_pair(i, j));
    }
  }

  int group_num = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (e[i][j] == 1 && group[i][j] == 0) {
        group_init(i, j, group_num++, n);
      }
    }
  }

  int res = solve(n);

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     printf("%d ", group[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("\n");
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     printf("%d ", check[i][j]);
  //   }
  //   printf("\n");
  // }

  printf("%d\n", res);

  return 0;
}
