#include <iostream>
#include <string>

using namespace std;
/*
ROT13
ROT13은 카이사르 암호의 일종으로 영어 알파벳을 13글자씩 밀어서 만든다.

https://www.acmicpc.net/problem/11655
*/
int main() {
  string line;
  string rec = "";
  getline(cin, line);

  for (int i = 0; i < line.size(); i++) {
    char c = line[i];
    if ('a' <= c && c <= 'z') {
      if (c + 13 > 'z') {
        rec += ('a' - 1) + (c + 13 - 'z');
      } else {
        rec += c + 13;
      }
    } else if ('A' <= c && c <= 'Z') {
      if (c + 13 > 'Z') {
        rec += ('A' - 1) + (c + 13 - 'Z');
      } else {
        rec += c + 13;
      }
    } else {
      rec += c;
    }
  }
  cout << rec << '\n';
  return 0;
}