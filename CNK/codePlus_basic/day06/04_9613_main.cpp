/*
GCD 합
https://www.acmicpc.net/problem/9613
*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  cin.ignore();

  while (T--) {
    string line, buff;
    getline(cin, line);
    vector<long long> nums;
    stringstream ss(line);
    while (ss >> buff) nums.push_back(stoll(buff));

    long long tot = 0;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = i+1; j < nums.size(); j++) {
        long long a = nums[i];
        long long b = nums[j];
        long long m = 2;
        long long gcd = 1;
        while (1) {
          if (m > a || m > b) {
            break;
          }

          if (a % m == 0 && b % m == 0) {
            a /= m;
            b /= m;
            gcd *= m;
            m = 2;
          } else {
            m++;
          }
        }
        // cout << gcd << ' ';
        tot += gcd;
      }
    }

    cout << tot << '\n';
  }

  return 0;
}