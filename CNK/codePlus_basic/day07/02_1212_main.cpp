/*
8진수 2진수
https://www.acmicpc.net/problem/1212
*/
#include <algorithm>
#include <iostream>

using namespace std;

string toBinary(int num) {
  string res = "";

  while (num > 0) {
    res += to_string(num % 2);
    num /= 2;
  }

  if (res.length() == 0) return res = "000";

  int r = res.length() % 3;
  if (r == 1) res += "00";
  if (r == 2) res += "0";

  reverse(res.begin(), res.end());

  return res;
}

int main(int argc, char const *argv[]) {
  string line;
  cin >> line;

  string res = "";
  for (int i = 0; i < line.length(); i++) {
    int num = line[i] - '0';
    res += toBinary(num);
  }

  for (int i = 0; i < res.length(); i++) {
    if (res[i] == '1') {
      res = res.substr(i, res.length() - i);
      break;
    }
    if (res.length() - 1 == i && res[i] == '0') res = "0";
  }

  cout << res;

  return 0;
}
