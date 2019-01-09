#include <iostream>
#include <queue>
#include <string>

using namespace std;

/*
큐 구현

https://www.acmicpc.net/problem/10845
*/
int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  queue<int> q;

  cin >> n;

  while (n--) {
    string command;
    cin.ignore();
    cin >> command;
    if (command == "push") {
      int num;
      cin >> num;
      q.push(num);
    }
    if (command == "pop") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.front() << '\n';
        q.pop();
      }
    }
    if (command == "size") {
      cout << q.size() << '\n';
    }
    if (command == "empty") {
      if (q.empty()) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
    if (command == "front") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.front() << '\n';
      }
    }
    if (command == "back") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.back() << '\n';
      }
    }
  }

  return 0;
}