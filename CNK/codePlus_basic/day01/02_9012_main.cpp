#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
괄호

https://www.acmicpc.net/problem/9012
*/

string solve(string s) {
  stack<char> stk;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      stk.push(s[i]);
    } else {
      if (stk.empty()) return "NO";
      stk.pop();
    }
  }
  if (stk.empty())
    return "YES";
  else
    return "NO";
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    cout << solve(s) << '\n';
  }

  return 0;
}