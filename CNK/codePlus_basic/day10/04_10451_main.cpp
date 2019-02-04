/*
순열 사이클
https://www.acmicpc.net/problem/10451
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int x, vector<vector<int>> &e, vector<bool> &check) {
  queue<int> q;
  q.push(x);
  check[x] = true;
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    for(int i = 0; i < e[node].size(); i++) {
      if(check[e[node][i]] == false) {
        q.push(e[node][i]);
        check[e[node][i]] = true;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<vector<int>> e(n+1);
    vector<bool> check(n+1);
    for(int i = 1; i <= n; i++) {
      int v;
      cin >> v;
      e[i].push_back(v);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
      if(check[i] == false) {
        bfs(i, e, check);
        cnt++;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
