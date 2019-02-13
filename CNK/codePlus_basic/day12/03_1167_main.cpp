/*
트리의 지름
https://www.acmicpc.net/problem/1167
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int maxDist[100001];
bool check[100001];

void bfs(int v, vector<vector<int>> &a, vector<vector<int>> &d) {  
  fill_n(maxDist, 100001, 0);
  fill_n(check, 100001, false);
  queue<int> q;
  check[v] = true;
  q.push(v);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < a[x].size(); i++) {
      int next = a[x][i];
      if (check[next] == false) {
        maxDist[next] = maxDist[x] + d[x][i];
        q.push(next);
        check[next] = true;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> a(n + 1);
  vector<vector<int>> d(n + 1);
  for (int i = 0; i < n; i++) {
    int u;
    scanf("%d", &u);
    while (true) {
      int v, dist;
      scanf("%d", &v);
      if (v == -1) break;
      scanf("%d", &dist);
      a[u].push_back(v);
      d[u].push_back(dist);
    }
  }

  int start = 1;
  bfs(start, a, d);
  for (int i = 2; i <= n; i++) {
    if (maxDist[i] > maxDist[start]) {
      start = i;
    }
  }
  bfs(start, a, d);
  int ans = maxDist[1];
  for (int i = 2; i <= n; i++) {
    if (ans < maxDist[i]) {
      ans = maxDist[i];
    }
  }
  printf("%d\n", ans);

  return 0;
}