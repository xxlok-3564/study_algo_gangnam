/*
나무 재테크
https://www.acmicpc.net/problem/16235
*/
#include <cstdio>

using namespace std;

int a[11][11];             // 추가 양분
int land[11][11];          // 땅의 양분
int l_tree[11][11][1012];  // [x][y][나이] = 나무의 개수
int d_tree[11][11][1012];  // [x][y][나이] = 나무의 개수
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                 {0, 1},   {1, -1}, {1, 0},  {1, 1}};
const int MAX_AGE = 1011;

void spring(int n) {
  // 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
  // 각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다.
  // 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다.
  // 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을
  // 먹지 못하고 즉시 죽는다.
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= MAX_AGE; k++) {
        d_tree[i][j][k] = 0;  // 죽은 나무 개수 초기화
        int eat_cnt = land[i][j] / k;
        if (l_tree[i][j][k] <= eat_cnt) {
          int eat_dng = l_tree[i][j][k] * k;
          land[i][j] -= eat_dng;
        } else {
          int eat_dng = eat_cnt * k;
          d_tree[i][j][k] = l_tree[i][j][k] - eat_cnt;  // 문제!
          l_tree[i][j][k] = eat_cnt;
          land[i][j] -= eat_dng;
          l_tree[i][j][0] -= d_tree[i][j][k];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = MAX_AGE; k > 1; k--) {
        l_tree[i][j][k] = l_tree[i][j][k - 1];
      }
      l_tree[i][j][1] = 0;
    }
  }
}

void summer(int n) {
  // 여름에는 봄에 죽은 나무가 양분으로 변하게 된다.
  // 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로
  // 추가된다. 소수점 아래는 버린다.

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= MAX_AGE; k++) {
        land[i][j] += (k / 2) * d_tree[i][j][k];
      }
    }
  }
}

void fall(int n) {
  // 가을에는 나무가 번식한다.
  // 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인
  // 나무가 생긴다. 어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1,
  // c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 이다. 상도의
  // 땅을 벗어나는 칸에는 나무가 생기지 않는다.
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int tot = 0;
      for (int d = 5; d <= MAX_AGE; d += 5) {
        tot += l_tree[i][j][d];
      }
      if(tot == 0) continue;
      for (int k = 0; k < 8; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (x > 0 && x <= n && y > 0 && y <= n) {
          l_tree[x][y][1] += tot;
          l_tree[x][y][0] += tot;          
        }
      }
    }
  }
}

void winter(int n) {
  // 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다.
  // 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      land[i][j] += a[i][j];
    }
  }
}

int main(int argc, char const *argv[]) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      land[i][j] = 5;
    }
  }

  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    l_tree[x][y][z] = 1;
    l_tree[x][y][0] = 1;
  }

  for (int i = 1; i <= k; i++) {
    // for (int i = 1; i <= n; i++) {
    //   for (int j = 1; j <= n; j++) {
    //     printf("%d ", l_tree[i][j][0]);
    //   }
    //   printf("\n");
    // }
    // printf("\n");

    spring(n);
    summer(n);
    fall(n);
    winter(n);
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     printf("%d ", l_tree[i][j][0]);
  //   }
  //   printf("\n");
  // }
  // printf("\n");

  int tot = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      tot += l_tree[i][j][0];
    }
  }
  printf("%d\n", tot);

  return 0;
}
