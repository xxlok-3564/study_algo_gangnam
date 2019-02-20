/*
잃어버린 괄호
https://www.acmicpc.net/problem/1541
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  string line;
  getline(cin, line);

  int tmp = 0;
  int jari = 1;
  long long tot = 0;
  bool is_minus = false;
  for (int i = 0; i < line.length(); i++) {
    char c = line[i];
    if (c >= '0' && c <= '9') {
      tmp = (tmp * 10) + (c - '0');
      if (line.length() - 1 == i) {
        if (is_minus == false) {
          tot += tmp;
        } else {
          tot -= tmp;
        }
      }
    } else {
      if (is_minus == true) {
        tot -= tmp;        
      } else {
        tot += tmp;
      }
      tmp = 0;
      jari = 1;
      if(c=='-') {
        is_minus = true;
      }
    }
  }

  cout << tot << '\n';

  return 0;
}
