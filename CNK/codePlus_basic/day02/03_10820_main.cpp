#include <iostream>
#include <string>

using namespace std;

int main() {
  string line;
  
  while(getline(cin, line)) {
    // 소문자, 대문자, 숫자, 공백
    int len = 4;
    int arr[len];
    fill_n(arr, len, 0);    

    for(int i = 0; i < line.size(); i++) {
      char c = line[i];
      if('a' <= c && c <= 'z') arr[0] += 1;
      if('A' <= c && c <= 'Z') arr[1] += 1;
      if('0' <= c && c <= '9') arr[2] += 1;
      if(c == ' ') arr[3] += 1;
    }

    for(int i = 0; i < len; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}