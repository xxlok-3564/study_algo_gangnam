#include <iostream>
#include <stack>

using namespace std;

/*
쇠막대기

https://www.acmicpc.net/problem/10799
*/

int main() {
  stack<int> stk;
  string line;
  getline(cin, line);

  int cnt = 0;

  for (int i = 0; i < line.size(); i++) {
    if (line[i] == '(') {
      stk.push(i);
    } else {
      if (i - stk.top() == 1) { // 레이저
        stk.pop();
        cnt += stk.size();
      } else if(!stk.empty()) {  // 쇠막대기 끝
        stk.pop();
        cnt += 1;
      }
    }
  }
  cout << cnt << '\n';

  return 0;
}