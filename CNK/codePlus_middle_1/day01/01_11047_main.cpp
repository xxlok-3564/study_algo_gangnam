/*
동전0
https://www.acmicpc.net/problem/11047
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int tot = 0;
  for (int i = n-1; i >= 0; i--) {    
    tot += k / a[i];
    k = k % a[i];
  }
  cout << tot;

  return 0;
}
