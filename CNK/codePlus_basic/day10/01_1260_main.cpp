/*
DFS 와 BFS
https://www.acmicpc.net/problem/1260
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void dfs(int x, vector<bool> &check, vector<vector<int>> &e) {
  stack<int> stk;
  stk.push(x);
  check[x] = true;
  cout << x << " ";
  while(!stk.empty()) {
    int node = stk.top();
    stk.pop();    
    for(int i = 0; i < e[node].size(); i++) {
      if(check[e[node][i]] == false) {
        stk.push(node);
        stk.push(e[node][i]);
        check[e[node][i]] = true;
        cout << e[node][i] << " ";
        break;
      }
    }
  }
}

void bfs(int x, vector<bool> &check, vector<vector<int>> &e) {
  queue<int> q;
  q.push(x);
  check[x] = true;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cout << node << " ";
    for (int i = 0; i < e[node].size(); i++) {
      if (check[e[node][i]] == false) {
        q.push(e[node][i]);
        check[e[node][i]] = true;
      }
    }
  }
}

int main() {
  int n, m, s;  // 정점 개수, 간선 개수, 출발점
  cin >> n >> m >> s;
  vector<vector<int>> e(n + 1);
  vector<bool> check_dfs(n + 1);
  vector<bool> check_bfs(n + 1);

  // 간선 입력
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  // 간선 정렬
  for (int i = 1; i <= n; i++) {
    sort(e[i].begin(), e[i].end());
  }

  dfs(s, check_dfs, e);
  cout << "\n";
  bfs(s, check_bfs, e);
  cout << "\n";
  return 0;
}