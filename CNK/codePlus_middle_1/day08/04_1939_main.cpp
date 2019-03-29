/**
 * 중량제한
 * https://www.acmicpc.net/problem/1939
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool go(int node, int limit, int ed, vector<vector<pair<int, int>>> &board, vector<bool> &visited) {
  if (visited[node]) {
    return false;
  }

  visited[node] = true;
  if (node == ed) {
    return true;
  }
  for (auto &p : board[node]) {

    int next = p.first;
    int cost = p.second;

    if (cost >= limit) {
      if (go(next, limit, ed, board, visited)) {
        return true;
      }
    }
  }

  return false;
}

int main() {

  /* 변수 셋팅 */
  int n, m;
  cin >> n >> m;
  
  vector<vector<pair<int, int>>> board(n+1);
  vector<bool> visited(n+1);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    board[a].push_back(make_pair(b, c));
    board[b].push_back(make_pair(a, c));    
  }

  int st, ed;
  cin >> st >> ed;

  /* 가능한 무게를 이분탐색으로 체크한다. */
  int left = 1;
  int right = 1000000000;
  int ans = 0;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    fill_n(visited.begin(), n+1, false);

    /* dfs를 통해 방문할 수 있는지 알아 본다. */
    if (go(st, mid, ed, board, visited)) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }  
  
  cout << ans << "\n";

  return 0;
}