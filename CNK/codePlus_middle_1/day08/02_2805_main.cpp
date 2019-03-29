/**
 * 나무 자르기
 * https://www.acmicpc.net/problem/2805 
 */

#include <iostream>
#include <vector>

using namespace std;

int maxH = 0;

void solution(long long left, long long right, long long M, vector<long long> &namu) {

  /* 제약 조건 */
  if(left > right) {
    return;
  } 

  /* 가져갈 수 있는 나무길이 확인 */
  long long len = 0;
  long long mid = left + (right - left) / 2;
  for (int i = 0; i < namu.size(); i++) {
    if (namu[i] > mid) {
      len += namu[i] - mid;
    }
  }
  // cout << "(" << left << ", " << right << ") " << mid << "\n";

  /* 나무 길이에 따라 다시 검사 */  
  if (len >= M) {
    maxH = maxH < mid ? mid : maxH;
    solution(mid + 1, right, M, namu);       
  } else {
    solution(left, mid - 1, M, namu); 
  }
}

int main(int argc, char const *argv[])
{  
  int N;        /* 나무 수 */
  long long M;  /* 가져가려는 나무의 길이 */

  cin >> N;
  cin >> M;
  vector<long long> namu(N);
  long long max = 0;
  for (int i = 0; i < N; i++) {
    cin >> namu[i];
    max = max < namu[i] ? namu[i] : max;
  }

  long long left = 1;
  long long right = max;  
  solution(left, right, M, namu);
  cout << maxH << '\n';

  return 0;
}
