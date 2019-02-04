/*
반복수열
https://www.acmicpc.net/problem/2331
*/
#include <iostream>
#include <map>

using namespace std;

long long pow(int num, int p) {
  long long tot = 0L;
  while (num > 0) {
    long long jari_su = num % 10;
    int temp = 1;
    for (int i = 0; i < p; i++) {
      temp *= jari_su;
    }
    tot += temp;
    num /= 10;
  }
  return tot;
}

int main(int argc, char const *argv[]) {
  int num, p;
  cin >> num >> p;
  map<long long, int> m;
  m[num] = 0;
  long long temp = num;
  for (int i = 1;; i++) {
    temp = pow(temp, p);    
    if(m.find(temp) != m.end()) {
      cout << m[temp] << '\n';
      break;
    }
    m[temp] = i; 
  }
  return 0;
}
