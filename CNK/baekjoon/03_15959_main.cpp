/*
체스판 여행1
https://www.acmicpc.net/problem/16959
*/
#include <iostream>
#include <vector>

using namespace std;


bool moveNight(int a, int b) {

}

// k: 0(나이트), 1(비숍), 2(룩)
bool isCanMove(int a, int b, int k, vector<pair<int, int>> points) {

}

int main(int argc, char const *argv[])
{
  int N, num;
  cin >> N;
  vector<pair<int, int>> points(N);  
  vector<vector<int>> board(N);
  vector<vector<int>> times(N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> num;
      points[num] = make_pair(i, j);
      board[i][j] = num;
      times[i][j] = -1;
    }
  }
  
  return 0;
}
