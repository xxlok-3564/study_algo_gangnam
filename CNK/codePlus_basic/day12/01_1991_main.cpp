/*
트리순회
https://www.acmicpc.net/problem/1991
*/
#include <iostream>

using namespace std;

int tree[26][2] = {-1, };

void preOrder(int num, int n) {
  if(num == -1 || num >= n) return;
  cout << char(num + 'A');
  preOrder(tree[num][0], n);
  preOrder(tree[num][1], n);
  return;
}

void inOrder(int num, int n) {
  if(num == -1 || num >= n) return;
  inOrder(tree[num][0], n);
  cout << char(num + 'A');
  inOrder(tree[num][1], n);
  return;
}

void postOrder(int num, int n) {
  if(num == -1 || num >= n) return;
  postOrder(tree[num][0], n);
  postOrder(tree[num][1], n);
  cout << char(num + 'A');
  return;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char a, b, c;
    cin >> a >> b >> c;
    int node = a - 'A';
    if (b == '.') {
      tree[node][0] = -1;
    } else {
      tree[node][0] = b - 'A';
    }
    if (c == '.') {
      tree[node][1] = -1;
    } else {
      tree[node][1] = c - 'A';
    }
  }

  preOrder(0, n);
  cout << '\n';
  inOrder(0, n);
  cout << '\n';
  postOrder(0, n);
  cout << '\n';
  
  return 0;
}
