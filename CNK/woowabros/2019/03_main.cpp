/*
#03
word	result
I love you	R olev blf
*/
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string word) {
    string answer = "";
    int n = word.length();
    for(int i = 0; i < n; i++) {
      char c = word[i];
      char change;
      if('A' <= c && c < 'Z') {
        // 대문자 경우
        change = 'A' + ('Z' - c);
      } else if('a' <= c && c < 'z') {
        // 소문자 경우
        change = 'a' + ('z' - c);
      } else {
        change = c;
      }
      answer += change;
    }
    
    return answer;
}

int main(int argc, char const *argv[])
{
  string word;
  getline(cin, word);
  solution(word);

  return 0;
}
