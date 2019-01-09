#include <iostream>
#include <queue>

using namespace std;

/*
조세퍼스 문제

https://www.acmicpc.net/problem/1158
*/
int main() {
  int n, m;
  queue<int> q;

  cin >> n;
  cin >> m;

  for(int i = 1; i <= n; i++) {
    q.push(i);
  }

  cout << '<';
  while(!q.empty()) {
    for(int i = 0; i < m-1; i++) {
      q.push(q.front());
      q.pop();
    }
    cout << q.front();    
    q.pop();
    if(!q.empty()) {
      cout << ", ";
    }
  }
  cout << '>';

  return 0;
}