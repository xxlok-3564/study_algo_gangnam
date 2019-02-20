/*
사다리 조작
https://www.acmicpc.net/problem/15684
*/
#include <iostream>

using namespace std;

int N, M, H;
int ans;

bool map[31][12];

bool check() {
  /* i번째 세로선에서 출발. */
  for (int i = 1; i <= N; i++) {
    /* current : 현재 위치하고 있는 세로선 */
    int current = i;    

    /* 한칸씩 내려간다. */
    for (int j = 1; j <= H; j++) {
      /* 사다리가 존재하면 이동을 한다. */
      /* 존재하지 않으면 그 세로선에 위치한다. current가 변화하지 않는다. */
      if (map[j][current] == true) {
        /* current세로선의 j번째 행에 사다리를 놓은경우 오른쪽으로 이동 */
        current += 1;
      } else if (current - 1 > 0 && map[j][current - 1] == true) {
        /* current-1세로선의 j번째 행에 사다리를 놓은 경우 왼쪽으로 이동 */
        current -= 1;
      }
    }

    /* 출발한 세로선에 도착한다면 계속한다. */
    /* 출발한 세로선에 도착하지 못한다면 false를 반환한다. */
    if (i == current)
      continue;
    else
      return false;
  }

  /* 정상적으로 모든 세로선을 확인했다면 true를 반환한다. */
  return true;
}

/* row:현재 행, cnt:현재 사다리를 놓은 개수, target:놓아야 할 사다리 개수 */
void go(int row, int col, int cnt, int target) {
  /* ans값을 구한 경우, 더 이상 진행할 필요가 없으므로 종료하여 시간을 줄인다.
   */
  // cout << row << '\n';
  if (ans != -1) return;

  if (cnt == target) {
    /* i번째가 i번째로 끝나는지 확인 */
    if (check()) {
      ans = cnt;
    }
    return;
  }

  for (int i = row; i <= H; i++) {
    /* 굳이 이렇게 하지 않아도 시간초과가 나지 않는다. */
    int tmp = 1;
    if(i == row) tmp = col;
    for (int j = tmp; j < N; j++) {
      if (map[i][j] == false) {
        /* 사다리를 안 놓은 경우 */
        
        /* 양 옆에 사다리 여부 확인 */
        if (map[i][j - 1] == false && map[i][j + 1] == false) {
          /* 사다리 놓기 */
          map[i][j] = true;
          go(i, j, cnt + 1, target);
          map[i][j] = false;
        }
      }
    }
  }

  return;
}

int main() {
  cin >> N >> M >> H;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    map[a][b] = true;
  }

  ans = -1;                   /* 임의의 값으로 ans를 지정 */
  for (int i = 0; i < 4; i++) /* 놓은 사다리 개수가 i개 일 경우 */
  {
    go(1, 1, 0, i);
    // cout << '\n';
    if (ans != -1) break;
  }

  cout << ans << endl;

  return 0;
}