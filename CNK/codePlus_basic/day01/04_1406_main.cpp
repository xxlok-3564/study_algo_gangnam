#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
에디터

https://www.acmicpc.net/problem/1406
*/

int main() {
  ios_base::sync_with_stdio(false);

  string str;
  int n;
  stack<char> left, right;

  cin >> str;
  cin >> n;
  
  for (int i = 0; i < str.size(); i++) {
    left.push(str[i]);
  }

  while (n--) {
    string command;

    cin.ignore();    
    cin >> command;

    if (command == "L") {
      if (!left.empty()) {
        right.push(left.top());
        left.pop();
      }
    }
    if (command == "D") {
      if (!right.empty()) {
        left.push(right.top());
        right.pop();
      }
    }
    if (command == "B") {
      if(!left.empty()) {
        left.pop();
      }
    }
    if (command == "P") {
      char c;
      cin >> c;
      left.push(c);  // char 단위
    }
  }

  while(!left.empty()) {
    right.push(left.top());
    left.pop();
  }

  while(!right.empty()) {
    cout << right.top();
    right.pop();
  }
  cout << '\n';

  return 0;
}