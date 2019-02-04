/*
이분그래프
https://www.acmicpc.net/problem/1707
*/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool dfs(int x, vector<vector<int>> &e, vector<int> &check) {
  stack<int> stk;
  stk.push(x);
  check[x] = 1;
  while (!stk.empty()) {
    int node = stk.top();
    stk.pop();
    for (int i = 0; i < e[node].size(); i++) {
      if (check[e[node][i]] == 0) {
        stk.push(node);
        stk.push(e[node][i]);
        check[e[node][i]] = check[node] == 1 ? 2 : 1;
        break;
      } else {
        if (check[node] == check[e[node][i]]) {
          return false;
        }
      }
    }
  }

  return true;
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n + 1);
    vector<int> check(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }

    bool is_ok = true;
    for (int i = 1; i <= n; i++) {
      if (check[i] == 0) {
        if (dfs(i, e, check) == false) {
          is_ok = false;
          break;
        }
      }
    }
    // for(int i = 1; i <= n; i++) {
    //   cout << check[i] << ' ';
    // }
    cout << (is_ok == true ? "YES" : "NO") << "\n";
  }

  return 0;
}
