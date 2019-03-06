/*
2072. 홀수만 더하기
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QSEhaA5sDFAUq
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, num;
  int tot;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    tot = 0;
    for(int j = 0; j < 10; j++) {
      cin >> num;
      if(num&1 == 1) {
        tot += num;
      }
    }
    cout << "#" << i << " " << tot << "\n";
  }
  
  return 0;
}
