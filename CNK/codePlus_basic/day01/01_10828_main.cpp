#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
스택 구현

https://www.acmicpc.net/problem/10828
*/

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  stack<string> stk;

  cin >> n;
  cin.ignore();

  while (n--) {
    string line;            // 명령어
    getline(cin, line);
    string buff;            // 버퍼
    stringstream ss(line);  // stringstream 에 명령어 넣기.

    vector<string> commands;  // token을 담을 commands
    while (ss >> buff) {
      commands.push_back(buff);
    }

    if (commands[0] == "push") {
      stk.push(commands[1]);
    }
    if (commands[0] == "pop") {
      if (stk.empty()) {
        cout << -1 << '\n';
      } else {
        cout << stk.top() << '\n';
        stk.pop();
      }
    }
    if (commands[0] == "size") {
      cout << stk.size() << '\n';
    }
    if (commands[0] == "empty") {
      if (stk.empty()) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
    if (commands[0] == "top") {
      if (stk.empty()) {
        cout << -1 << '\n';
      } else {
        cout << stk.top() << '\n';
      }
    }
  }

  return 0;
}