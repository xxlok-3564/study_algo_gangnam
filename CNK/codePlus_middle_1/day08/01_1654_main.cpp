/*
 * 동전 자르기
 * https://www.acmicpc.net/problem/1654
 * */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxLen = 0;

void solution(long long left, long long right, int &K, vector<int> &lan) {

  /* 제약 조건 */
  if(left > right) {
    return;
  }

  /* 중간 위치의 길이를 구해 몇개로 나눌수 있는지 구한다. */
  long long mid = (left + right)/2;
  // cout << "(" << left << ", " << right << ") " << mid << "\n";

  int cnt = 0;
  for(int i = 0; i < lan.size(); i++) {
    cnt += lan[i] / mid;
  }

  /* 나눈 개수를 비교해서 함수를 재호출할지 말지 정한다. */
  if(cnt == K) {
    maxLen = maxLen < mid ? mid : maxLen;
    solution(mid+1, right, K, lan);
  } else if(cnt < K) {
    solution(left, mid-1, K, lan);
  }
}

int main(int argc, char const *argv[])
{
  int N, K;
  cin >> N;
  cin >> K;
  vector<int> lan(N);
  for(int i = 0; i < N; i++) {
    cin >> lan[i];
  }

  sort(lan.begin(), lan.end());
  solution(1, lan[N-1], K, lan);  /* 주의) 0부터아니다... */
  cout << maxLen << '\n';

  return 0;
}
