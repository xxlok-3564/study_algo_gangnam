/*
섬의 개수
https://www.acmicpc.net/problem/4963
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int directions[8][2] = {{0, 1},   {0, -1}, {-1, 0}, {1, 0},
                        {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

void solve(int x, int y, int w, int h, vector<vector<int>> &map,
           vector<vector<bool>> &check) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  check[x][y] = true;

  while (!q.empty()) {
    int node_x = q.front().first;
    int node_y = q.front().second;
    q.pop();

    for (int i = 0; i < 8; i++) {
      int tmp_x = node_x + directions[i][0];
      int tmp_y = node_y + directions[i][1];

      if (tmp_x >= 0 && tmp_x < h && tmp_y >= 0 && tmp_y < w &&
          map[tmp_x][tmp_y] == 1 && check[tmp_x][tmp_y] == false) {
        q.push(make_pair(tmp_x, tmp_y));
        check[tmp_x][tmp_y] = true;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;

    vector<vector<int>> map(h);
    vector<vector<bool>> check(h);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int tmp;
        cin >> tmp;
        map[i].push_back(tmp);
        check[i].push_back(false);
      }
    }

    int cnt = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (map[i][j] == 1 && check[i][j] == false) {
          solve(i, j, w, h, map, check);
          cnt++;
        }
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
