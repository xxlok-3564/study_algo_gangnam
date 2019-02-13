/*
아기상어
https://www.acmicpc.net/problem/16236
*/
#include <cstdio>
#include <queue>

using namespace std;

int directions[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int map[20][20];        // 지도
int distances[20][20];  // 거리
int fish_cnt = 0;       // 남은 물고기 개수
int shark_loc[2];       // 상어 위치
int shark_size = 2;     // 상어 크기
int shark_eat = 0;      // 상어가 먹은 고기수
int n;                  // 지도의 크기

// 거리 초기화
void init_distances() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      distances[i][j] = -1;
    }
  }
}

// 거리 체크
void distance(int start_x, int start_y) {
  init_distances();
  queue<pair<int, int>> q;
  q.push(make_pair(start_x, start_y));
  distances[start_x][start_y] = 0;

  while (!q.empty()) {
    int node_x = q.front().first;
    int node_y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int tmp_x = node_x + directions[i][0];
      int tmp_y = node_y + directions[i][1];

      if (tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < n &&
          map[tmp_x][tmp_y] <= shark_size) {
        if (distances[tmp_x][tmp_y] == -1 ||
            distances[tmp_x][tmp_y] > distances[node_x][node_y] + 1) {
          q.push(make_pair(tmp_x, tmp_y));
          distances[tmp_x][tmp_y] = distances[node_x][node_y] + 1;
        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  scanf("%d", &n);

  // 0: 빈 칸
  // 1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
  // 9: 아기 상어의 위치
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j] > 0 && map[i][j] <= 6) {
        fish_cnt++;
      } else if (map[i][j] == 9) {
        map[i][j] = 0;    // 어차피 지도상으론 빈공간이다.
        shark_loc[0] = i;
        shark_loc[1] = j;
      }
    }
  }

  int tot = 0;
  for (int i = 0; i < fish_cnt; i++) {
    distance(shark_loc[0], shark_loc[1]);
    int min_distance = 500;
    int min_x = -1;
    int min_y = -1;

    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        if (distances[x][y] != -1 && map[x][y] > 0 && map[x][y] < shark_size &&
            min_distance > distances[x][y]) {
          min_distance = distances[x][y];
          min_x = x;
          min_y = y;
        }
      }
    }
       
    if (min_x == -1 && min_y == -1) break;

    tot += min_distance;    
    map[min_x][min_y] = 0;    // 이동할 자리는 빈공간
    shark_loc[0] = min_x;
    shark_loc[1] = min_y;
    shark_eat++;
    if (shark_eat == shark_size) {
      shark_eat = 0;
      shark_size++;
    }
  }

  printf("%d", tot);

  return 0;
}
