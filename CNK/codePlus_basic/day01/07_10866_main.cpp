#include <deque>
#include <iostream>

using namespace std;
/*
덱

https://www.acmicpc.net/problem/10866
*/
int main() {
  deque<int> dq;
  int n;
  cin >> n;

  while (n--) {
    cin.ignore();
    string command;
    cin >> command;

    if (command == "push_front") {
      int num;
      cin >> num;
      dq.push_front(num);
    }
    if (command == "push_back") {
      int num;
      cin >> num;
      dq.push_back(num);
    }
    if (command == "pop_front") {
      if (dq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << dq.front() << '\n';
        dq.pop_front();
      }
    }
    if (command == "pop_back") {
      if (dq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << dq.back() << '\n';
        dq.pop_back();
      }
    }
    if (command == "size") {
      cout << dq.size() << '\n';
    }
    if (command == "empty") {
      if (dq.empty()) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
    if (command == "front") {
      if (dq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << dq.front() << '\n';
      }
    }
    if (command == "back") {
      if (dq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << dq.back() << '\n';
      }
    }
  }

  return 0;
}