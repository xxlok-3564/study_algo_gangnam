/*
치킨배달
https://www.acmicpc.net/problem/15686
*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N, M, ans;
// 주문하는 사람
vector<pair<int, int>> applicant;
// 치킨 집 위치
vector<pair<int, int>> place;
int chk[50];
int map[51][51];

int dfs(int idx, int cnt) {  
  
  cout << "<" << idx << ", " << cnt <<">\n";
  for(int i = 0; i < 50; i++) {
    cout << chk[i] << ' ';
  }
  cout << "\n";

  // 범위 체크
  if (idx > place.size()) {
    return 0;
  }  

  // 선택된 치킨 집의 갯수가 주어진 조건과 같을 때
  if (cnt == M) {
    int temp = 0;
    // 주문하는 집에서 가장 가까운 치킨집 위치를 찾아 dist에 저장
    for (int i = 0; i < applicant.size(); i++) {
      int dist = 987654321;
      for (int j = 0; chk[j] != -1; j++) {
        int appR = applicant[i].first;
        int appC = applicant[i].second;
        int plR = place[chk[j]].first;
        int plC = place[chk[j]].second;

        dist = min(dist, abs(appR - plR) + abs(appC - plC));
      }
      temp += dist;
    }
    ans = min(ans, temp);
    cout << "temp -> " << temp << " ans -> "  << ans <<"\n";
    return 0;
  }

  // idx번째 치킨 집에서 치킨 주문 O
  chk[cnt] = idx;
  dfs(idx + 1, cnt + 1);  

  // idx번째 치킨 집에서 치킨을 주문 X
  chk[cnt] = -1;
  dfs(idx + 1, cnt);
  return 0;
}

int main() {
  cin >> N >> M;
  memset(chk, -1, sizeof(chk));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];

      if (map[i][j] == 1) {
        applicant.push_back(make_pair(i, j));
      } else if (map[i][j] == 2) {
        place.push_back(make_pair(i, j));
      }
    }
  }

  ans = 987654321;
  dfs(0, 0);

  cout << ans;
  return 0;
}