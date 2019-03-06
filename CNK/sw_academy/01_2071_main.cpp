/*
평균구하기
https://www.swexpertacademy.com/main/code/problem/problemSubmitHistory.do?contestProbId=AV5QRnJqA5cDFAUq
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  int num;
  double tot;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    tot = 0;
    for(int j = 0; j < 10; j++) {
      cin >> num;
      tot += num;
    }
    cout << "#" << i << " " << round(tot/10) << "\n";
  }
  return 0;
}
