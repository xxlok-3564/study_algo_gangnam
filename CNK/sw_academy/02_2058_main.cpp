/*
자릿수 더하기
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QPRjqA10DFAUq&categoryId=AV5QPRjqA10DFAUq&categoryType=CODE
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;

  int tot = 0;
  while(n > 0) {    
    tot += n % 10;
    n /= 10;
  }
  cout << tot;

  return 0;
}
