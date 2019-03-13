/*
파이프 옮기기
https://www.acmicpc.net/problem/17069
*/
#include <iostream>
#include <queue>

using namespace std;

// struct Pipe
// {
//   int x, y;
//   int dir;
//   int cnt;
//   Pipe(int _x, int _y, int _dir, int _cnt) : x(_x), y(_y), dir(_dir),
//   cnt(_cnt) {}
// };

struct Pipe {
  long long u;  // 위쪽
  long long c;  // 대각선
  long long l;  // 왼쪽
  Pipe(long long _u, long long _c, long long _l) : u(_u), c(_c), l(_l) {}
};


void print_root(vector<vector<Pipe>> &check, int n) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cout << check[i][j].c + check[i][j].u + check[i][j].l << " ";
    }
    cout << "\n";
  }
  cout << "\n\n";
}

// void solve(int x, int y, int n, int direction, vector<vector<int>> &map,
//            vector<vector<long long>> &check) {

//   queue<Pipe> q;
//   Pipe obj = {x, y, direction, 1};
//   check[x][y] = 1;
//   q.push(obj);

//   while (!q.empty()) {
//     // print_root(check, n);
//     int node_x = q.front().x;
//     int node_y = q.front().y;
//     int node_dir = q.front().dir;
//     int node_cnt = q.front().cnt;
//     // cout << node_dir << " ";
//     q.pop();

//     for (int i = 0; i < 3; i++) {
//       int next_x = node_x + dir_1[node_dir][i][0];
//       int next_y = node_y + dir_1[node_dir][i][1];
//       if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n &&
//           map[next_x][next_y] == 0) {
//         Pipe next_obj = {next_x, next_y, dir_2[node_dir][i][0], node_cnt};
//         if (dir_2[node_dir][i][0] == 2) {
//           // 대각선일 경우...
//           // cout << next_obj.dir << " ";
//           if (map[node_x][node_y + 1] == 0 && map[node_x + 1][node_y] == 0) {
//             q.push(next_obj);
//             check[next_x][next_y] += node_cnt;
//           }
//         } else if (dir_2[node_dir][i][0] != -1) {
//           // 대각선이 아닐 경우...
//           // cout << next_obj.dir << " ";
//           q.push(next_obj);
//           check[next_x][next_y] += node_cnt;
//         }
//       }
//     }
//   }
// }

void solve(vector<vector<int>> &map, vector<vector<Pipe>> &check, int n) {
  check[1][2].l = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if(map[i][j] == 0) {
        check[i][j].l += check[i][j-1].l + check[i][j-1].c;
        check[i][j].u += check[i-1][j].u + check[i-1][j].c;
        if(map[i][j-1] == 0 && map[i-1][j] == 0) {
          check[i][j].c += check[i-1][j-1].c + check[i-1][j-1].l + check[i-1][j-1].u;
        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int n, num;

  cin >> n;
  vector<vector<int>> map(n + 1);
  vector<vector<Pipe>> check(n + 1);

  for(int i = 0; i <= n; i++) {
    // Pipe obj = {0, 0, 0};
    map[0].push_back(0);
    check[0].push_back({0, 0, 0});
  }

  for (int i = 1; i <= n; i++) {
    // Pipe obj = {0, 0, 0};
    map[i].push_back(0);
    check[i].push_back({0, 0, 0});
    for (int j = 1; j <= n; j++) {      
      cin >> num;
      map[i].push_back(num);
      check[i].push_back({0, 0, 0});
    }
  }
  // print_root(check, n);
  solve(map, check, n);
  // print_root(check, n);
  cout << check[n][n].c + check[n][n].u + check[n][n].l << "\n";

  return 0;
}
