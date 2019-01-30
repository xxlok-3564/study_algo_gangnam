/*
K번째 수
https://www.acmicpc.net/problem/11004
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  nth_element(v.begin(), v.begin() + (k - 1), v.end(), std::less<long long>());
  cout << v[k - 1] << "\n";

  return 0;
}
