/*
#05
*/
#include <cstdio>

#include <string>
#include <vector>

using namespace std;

int cntClab(int num) {
  int cnt = 0;
  while (num > 0) {
    int tmp = num % 10;
    if(tmp == 3 || tmp == 6 || tmp == 9) {
      cnt++;
    }
    num /= 10;
  }
  return cnt;
}

int solution(int number) {
  int answer = 0;

  for (int i = 1; i <= number; i++) {
    answer += cntClab(i);
  }

  return answer;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
