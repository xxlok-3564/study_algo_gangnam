/*
트리의 부모 찾기
https://www.acmicpc.net/problem/11725
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {  
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1);
  vector<bool> check(n + 1);
  vector<int> parents(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }

  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < a[x].size(); i++) {
      int next = a[x][i];
      if (check[next] == false) {
        check[next] = true;
        parents[next] = x;
        q.push(next);
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << parents[i] << '\n';
  }

  return 0;
}