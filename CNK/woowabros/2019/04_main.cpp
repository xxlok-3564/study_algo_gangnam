/*
#04
*/
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int multiAll(int num) {
  int tot = 1;
  while (num > 0) {
    tot *= num % 10;
    num /= 10;
  }
  return tot;
}

int addAll(int num) {
  int tot = 0;
  while (num > 0) {
    tot += num % 10;
    num /= 10;
  }
  return tot;
}

int maxCalc(int num1, int num2) {
  int left = -1;
  int right = -1;
  // 왼쪽 페이지
  if (addAll(num1) > multiAll(num1)) {
    left = addAll(num1);
  } else {
    left = multiAll(num1);
  }

  // 오른쪽 페이지
  if (addAll(num2) > multiAll(num2)) {
    right = addAll(num2);
  } else {
    right = multiAll(num2);
  }

  if(left > right) {
    return left;
  } else {
    return right;
  }  
}

int solution(vector<int> pobi, vector<int> crong) {
  int answer = 0;

  // 예외 사항인 경우
  if (pobi[0] > 0 && pobi[0] < 400 && pobi[1] > 1 && pobi[1] <= 400 &&
      crong[0] > 0 && crong[0] < 400 && crong[1] > 1 && crong[1] <= 400) {  // 1~400 인지 확인
    if (pobi[0] % 2 == 1 && pobi[1] % 2 == 0 && crong[0] % 2 == 1 && crong[1] % 2 == 0) {  // 홀수, 짝수, 홀수, 짝수 확인
      if (pobi[1] == pobi[0] + 1 && crong[1] == crong[0] + 1) {  // 오른쪽 페이지가 왼쪽페이지 다음인지 확인
      } else {
        return answer = -1;
      }
    } else {
      return answer = -1;
    }
  } else {
    return answer = -1;
  }

  // 포비와 크롱의 점수 비교
  int max_pobi = maxCalc(pobi[0], pobi[1]);
  int max_crong = maxCalc(crong[0], crong[1]);  

  if(max_pobi > max_crong) {  // 포비가 이김.
    answer = 1;
  } else if(max_pobi < max_crong) { // 크롱이 이김.
    answer = 2;
  } else {  // 무승부.
    answer = 0;
  }

  return answer;
}

int main(int argc, char const *argv[]) {
  cout << addAll(999);

  return 0;
}
