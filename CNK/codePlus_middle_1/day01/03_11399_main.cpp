/*
ATM
https://www.acmicpc.net/problem/11399
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) {    
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int tot = 0;
  for(int i = 0; i < n; i++) {    
    for(int j = 0; j <= i; j++) {
      tot += v[j];
    }
  }
  cout << tot;
  return 0;
}
