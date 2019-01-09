#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
/*
접미사 배열
https://www.acmicpc.net/problem/11656
*/
int main() {
  string s;
  cin >> s;  
  vector<string> arr;

  for (int i=0; i < s.length(); i++) {
    arr.push_back(s.substr(i, s.length()-i));
  }

  // 사전순 정렬
  sort(arr.begin(), arr.end());
  for(int i=0; i < s.length(); i++) {
    cout << arr[i] << '\n';
  }

  return 0;
}