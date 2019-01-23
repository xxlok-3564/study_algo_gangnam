/*
2진수 8진수
https://www.acmicpc.net/problem/1373
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  string line;
  cin >> line;
  int r = line.length() % 3;
  if (r == 1) line = "00" + line;
  if (r == 2) line = "0" + line;

  string res = "";
  for (int i = 0; i < line.length(); i += 3) {
    int a = line[i] - '0';
    int b = line[i + 1] - '0';
    int c = line[i + 2] - '0';

    int val = (a * 2 * 2) + (b * 2) + (c * 1);
    res += (char)('0' + val);
  }

  cout << res;

  return 0;
}