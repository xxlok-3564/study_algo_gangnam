/*
단지번호붙이기
https://www.acmicpc.net/problem/2667
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int solve(int x, int y, int flag, vector<vector<int>> &map, vector<vector<int>> &check) {
  int cnt = 1;
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  check[x][y] = flag;

  while(!q.empty()) {
    int node_x = q.front().first;
    int node_y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int tmp_x = node_x + directions[i][0];
      int tmp_y = node_y + directions[i][1];
      if(tmp_x >= 0 && tmp_x < map.size() &&
         tmp_y >= 0 && tmp_y < map.size() &&
         map[tmp_x][tmp_y] == 1 && check[tmp_x][tmp_y] == 0) {
        q.push(make_pair(tmp_x, tmp_y));
        check[tmp_x][tmp_y] = flag;
        cnt++;
      }
    }
  }

  return cnt;
}

int main() {
  int n;
  cin >> n;  
  vector<vector<int>> map(n);
  vector<vector<int>> check(n);
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < n; j++) {
      map[i].push_back(tmp[j]-'0');
      check[i].push_back(0);
    }
  }

  int flag = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(map[i][j] == 1 && check[i][j] == 0) {
        int cnt = solve(i, j, flag++, map, check);
        nums.push_back(cnt);
      }
    }
  }  

  sort(nums.begin(), nums.end());

  cout << nums.size() << '\n';
  for(int i = 0; i < nums.size(); i++) {
    cout << nums[i] << '\n';
  }

  return 0;
}