/*
연결 요소의 개수
https://www.acmicpc.net/problem/11724
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs(int x, vector<vector<int>> &e, vector<bool> &check) {
  stack<int> stk;
  stk.push(x);
  check[x] = true;

  while(!stk.empty()) {
    int node = stk.top();
    stk.pop();
    check[node] = true;
    for(int i = 0; i < e[node].size(); i++) {
      if(check[e[node][i]] == false) {
        stk.push(node);
        stk.push(e[node][i]);
        check[e[node][i]] = true;
        break;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int n, m; // 정점 개수, 간선 개수
  cin >> n >> m;
  vector<vector<int>> e(n+1);
  vector<bool> check(n+1);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  for(int i = 1; i <= n; i++) {
    sort(e[i].begin(), e[i].end());
  }

  int cnt = 0;
  for(int i = 1; i <= n; i++) { // 정점 1~n
    if(check[i] == false) {
      dfs(i, e, check);
      cnt++;
    }
  }
  cout << cnt;

  return 0;
}