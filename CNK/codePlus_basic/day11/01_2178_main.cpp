/*
미로탐색
https://www.acmicpc.net/problem/2178
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void solve(int x, int y, int n, int m, vector<vector<int>> &e, vector<vector<int>> &check) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  check[x][y] = 1;

  while(!q.empty()) {
    int node_x = q.front().first;
    int node_y = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      int tmp_x = node_x + directions[i][0];
      int tmp_y = node_y + directions[i][1];

      if(tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < m && e[tmp_x][tmp_y] == 1) {
        if(check[tmp_x][tmp_y] == 0 || check[tmp_x][tmp_y] > check[node_x][node_y] + 1) {
          check[tmp_x][tmp_y] = check[node_x][node_y] + 1;
          q.push(make_pair(tmp_x, tmp_y));
        }
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> e(n);
  vector<vector<int>> check(n);
  for(int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for(int j = 0; j < m; j++) {
      e[i].push_back(str[j] - '0');
      check[i].push_back(0);
    }
  }


  solve(0, 0, n, m, e, check);
  cout << check[n-1][m-1];

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < m; j++) {
  //     cout << check[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  return 0;
}
