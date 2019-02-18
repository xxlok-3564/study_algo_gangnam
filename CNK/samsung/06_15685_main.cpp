/*
드래곤 커브
https://www.acmicpc.net/problem/15685
*/
#include <cstdio>
#include <vector>

#define MAX 2000

using namespace std;

bool map[MAX][MAX];
int rotation_dir[4] = {1, 2, 3, 0};
int rotation_xy[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int rect_xy[3][2] = {{0, 1}, {1, 0}, {1, 1}};

void draw_map(int x, int y) {
  x += MAX / 2;
  y += MAX / 2;
  map[y][x] = true;
}

void draw_curve(int x, int y, int d, int g, auto &curve, auto &curve_loc,
                int idx) {
  draw_map(x, y);

  // printf("<%d, %d>\n", x, y);

  curve[idx].push_back(d);
  x += rotation_xy[d][0];
  y += rotation_xy[d][1];
  curve_loc[idx].push_back(make_pair(x, y));
  draw_map(x, y);

  // printf("<%d, %d>\n", x, y);
  for (int i = 1; i <= g; i++) {
    int len = curve[idx].size() - 1;
    for (int j = len; j >= 0; j--) {
      int rot_dir = rotation_dir[curve[idx][j]];
      curve[idx].push_back(rot_dir);
      x += rotation_xy[rot_dir][0];
      y += rotation_xy[rot_dir][1];
      curve_loc[idx].push_back(make_pair(x, y));
      draw_map(x, y);
      // printf("<%d, %d>\n", x, y);
    }
  }

  return;
}

int count_rect() {
  int res = 0;

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (map[i][j] == true) {
        // printf("here<%d, %d>\n", i ,j);
        int cnt = 1;
        for (int k = 0; k < 3; k++) {
          // printf("<%d, %d>\n", i + rect_xy[k][0], j + rect_xy[k][1]);
          if (map[i + rect_xy[k][0]][j + rect_xy[k][1]] == true)
            cnt++;
          else
            break;
        }
        if (cnt == 4) res++;
      }
    }
  }

  return res;
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  vector<vector<int>> curve(n);
  vector<vector<pair<int, int>>> curve_loc(n);
  for (int i = 0; i < n; i++) {
    int x, y, d, g;
    scanf("%d %d %d %d", &x, &y, &d, &g);
    draw_curve(x, y, d, g, curve, curve_loc, i);
    // printf("\n");
  }
  int ans = count_rect();
  // for(int i = 0; i < MAX; i++) {
  //   for(int j = 0; j < MAX; j++) {
  //     printf("%3d ", map[i][j]);
  //   }
  //   printf("\n");
  // }
  printf("%d", ans);  

  return 0;
}
