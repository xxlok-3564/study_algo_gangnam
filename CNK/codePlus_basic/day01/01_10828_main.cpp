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
    getline(cin, line);     // 명령어 입력받는다.
    string buff;            // 버퍼
    stringstream ss(line);  // string을 stream에 넣는다.

    vector<string> commands;  // 명령어를 넣을 vector
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