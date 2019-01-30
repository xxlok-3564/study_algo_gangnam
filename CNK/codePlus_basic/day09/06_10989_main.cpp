/*
수 정렬하기3
https://www.acmicpc.net/problem/10989
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  vector<int> v(10001, 0);

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v[num]++;
  }

  for (int i = 1; i < 10001; i++) {
    for (int j = 0; j < v[i]; j++) {
      cout << i << "\n";
    }
  }

  return 0;
}
