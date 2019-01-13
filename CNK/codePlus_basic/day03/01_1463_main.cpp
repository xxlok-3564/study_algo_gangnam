#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr;
  arr.push_back(0); // index :: 0
  arr.push_back(0); // index :: 1
  arr.push_back(1); // index :: 2

  int num;
  cin >> num;

  for (int i = 3; i <= num; i++) {
    int cnt = i;  // 최소 연산횟수 :: 초기화는 MAX값

    if(i%3 == 0) {
      cnt = arr[i/3]+1 < cnt ? arr[i/3]+1 : cnt;
    }
    if(i%2 == 0) {
      cnt = arr[i/2]+1 < cnt ? arr[i/2]+1 : cnt;
    }
    if(i-1 > 0) {
      cnt = arr[i-1]+1 < cnt ? arr[i-1]+1 : cnt;
    }

    arr.push_back(cnt);
  }

  cout << arr[num] << '\n';

  return 0;
}