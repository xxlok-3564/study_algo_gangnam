/*
무지의 먹방 라이브
https://programmers.co.kr/learn/courses/30/lessons/42891
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vv(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << "\n\n";
}

int solution(vector<int> food_times, long long k) {
  int answer = 0;
  int n = food_times.size();
  long long remain_time = k+1;
  long long avg;
  bool isChange;
  
  do {
    isChange = false;
    avg = remain_time / n;
    if(avg == 0) {
      avg = 1;
    }

    for (int i = 0; i < n; i++) {
      if(food_times[i] != 0) {
        isChange = true;      
        int val = food_times[i] - avg;
        remain_time -= avg;
        if(val < 0) {
          remain_time += -val;
          food_times[i] = 0;
        } else {
          food_times[i] = val;
        }

        if(remain_time == 0) {
          answer = i;
          break;
        }
      }
    }

    if(!isChange) {
      answer = -2;
      break;
    }

    // print_vv(food_times);
  } while (remain_time > 0);

  cout << answer+1 << "\n";

  return answer+1;
}

int main(int argc, char const *argv[]) {
  int n, num;
  long long k;
  cin >> n;
  cin >> k;
  vector<int> food_times(n);
  for (int i = 0; i < n; i++) {
    cin >> num;
    food_times[i] = num;
  }

  solution(food_times, k);

  return 0;
}
