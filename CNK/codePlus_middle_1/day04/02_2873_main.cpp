#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int a[1000][1000];

/* 문자열s에 문자c를 cnt개수만큼 붙인다. */
void append(string &s, char c, int cnt) {
  for (int i = 0; i < cnt; i++) {
    s += c;
  }
}

int main() {
  /* 문제 입력 받기 */
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  /* 정답 string 만들기 */
  /* 출발지점에서 시작하는 이동방향 s */
  string s = "";
  if (n % 2 == 1) {
    /* 행(n)이 홀수 이면 RDL을 이용한다. */
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        append(s, 'R', m - 1);
        if (i != n - 1) {
          append(s, 'D', 1);
        }
      } else {
        append(s, 'L', m - 1);
        append(s, 'D', 1);
      }
    }
  } else if (m % 2 == 1) {
    /* 열(n)이 홀수이면 DUR을 이용한다. */
    for (int j = 0; j < m; j++) {
      if (j % 2 == 0) {
        append(s, 'D', n - 1);
        if (j != m - 1) {
          append(s, 'R', 1);
        }
      } else {
        append(s, 'U', n - 1);
        append(s, 'R', 1);
      }
    }
  } else {
    /* 그 밖에 모두 짝수일경우 */
    /* 방문하지 않을 가장 작은 기쁨val 위치를 찾는다. */

    /* 방문하지 않을 위치 */
    int x, y;
    x = 0;
    y = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) % 2 == 1) {
          if (a[x][y] > a[i][j]) {
            x = i;
            y = j;
          }
        }
      }
    }
    /* 위쪽 행번호 */
    int x1 = 0;
    /* 왼쪽 열번호 */
    int y1 = 0;
    /* 아래쪽 행번호 */
    int x2 = n - 1;
    /* 오른쪽 열번호 */
    int y2 = m - 1;
    /* 도착지점에서 시작하는 이동방향 s2 */
    string s2 = "";

    /* 행을 기준으로 위, 아래를 두칸씩 줄여나간다. */
    while (x2 - x1 > 1) {
      /* 2줄씩 지우기때문에 2로 나눈값을 확인한다. */
      if (x1 / 2 < x / 2) {
        append(s, 'R', m - 1);
        append(s, 'D', 1);
        append(s, 'L', m - 1);
        append(s, 'D', 1);
        x1 += 2;
      }
      if (x / 2 < x2 / 2) {
        append(s2, 'R', m - 1);
        append(s2, 'D', 1);
        append(s2, 'L', m - 1);
        append(s2, 'D', 1);
        x2 -= 2;
      }
    }

    /* 열을 기준으로 왼쪽, 오른쪽을 두칸찍 줄여나간다. */
    while (y2 - y1 > 1) {
      /* 2줄씩 지우기때문에 2로 나눈값을 확인한다. */
      if (y1 / 2 < y / 2) {
        append(s, 'D', 1);
        append(s, 'R', 1);
        append(s, 'U', 1);
        append(s, 'R', 1);
        y1 += 2;
      }
      if (y / 2 < y2 / 2) {
        append(s2, 'D', 1);
        append(s2, 'R', 1);
        append(s2, 'U', 1);
        append(s2, 'R', 1);
        y2 -= 2;
      }
    }

    /* 지워진 칸의 y의 위치에 따라 마지막 이동 */
    if (y == y1) {
      append(s, 'R', 1);
      append(s, 'D', 1);
    } else {
      append(s, 'D', 1);
      append(s, 'R', 1);
    }
    reverse(s2.begin(), s2.end());
    s += s2;
  }
  cout << s << '\n';

  return 0;
}