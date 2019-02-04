/*
텀 프로젝트
https://www.acmicpc.net/problem/9466
*/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solve(int x, vector<int> &e, vector<int> &check, vector<int> &order) {
  int cnt = 1;
  stack<int> stk;
  stk.push(x);
  check[x] = x;
  order[x] = cnt;

  while (!stk.empty()) {
    int node = stk.top();
    stk.pop();
    if (check[e[node]] == 0) {      
      stk.push(e[node]);
      check[e[node]] = x;
      order[e[node]] = ++cnt;
    } else if(check[e[node]] == x) {
      return cnt - order[e[node]] + 1;
    } else {
      return 0;
    }
  }
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> e(n + 1);
    vector<int> check(n + 1);
    vector<int> order(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> e[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (check[i] == 0) {
        int team_su = solve(i, e, check, order);        
        cnt += team_su;
        // cout << i << " cnt :: " << team_su << " // ";
      }
    }
    // cout << '\n';
    cout << n-cnt << '\n';
  }

  return 0;
}
