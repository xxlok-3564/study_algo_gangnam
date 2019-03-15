/*
뿌요뿌요
https://www.acmicpc.net/problem/11559
*/
#include <cstdio>
#include <vector>

using namespace std;

char board[12][6];
bool check[12][6];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void print_arr(auto &board) {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

// board와 check를 정렬
void arrange() {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      check[i][j] = false;
    }
  }

  for (int i = 0; i < 6; i++) {
    int piv = 11;
    for (int j = piv; j >= 0; j--) {
      if (board[j][i] != '.') {
        char tmp_c = board[j][i];
        board[j][i] = '.';
        board[piv--][i] = tmp_c;
      }
    }
  }
}

void dfs(int x, int y, char c, vector<pair<int, int>> &v) {
  check[x][y] = true;
  v.push_back(make_pair(x, y));

  for (int i = 0; i < 4; i++) {
    int node_x = x + dir[i][0];
    int node_y = y + dir[i][1];

    if (node_x >= 0 && node_x < 12 && node_y >= 0 && node_y < 6) {
      if (board[node_x][node_y] == c && check[node_x][node_y] == false) {
        dfs(node_x, node_y, c, v);
      }
    }
  }
}

bool bumb() {
  bool isChange = false;
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      if (board[i][j] != '.' && check[i][j] == false) {
        vector<pair<int, int>> v;
        dfs(i, j, board[i][j], v);
        if (v.size() >= 4) {          
          for (int k = 0; k < v.size(); k++) {
            board[v[k].first][v[k].second] = '.';
          }
          isChange = true;
        }
      }
    }
  }
  
  return isChange;
}

void solution() {
  int answer = 0;
  bool isChange;
  while(bumb()) {
    answer++;
    arrange();
  }

  printf("%d", answer);
}

int main(int argc, char const *argv[]) {
  char c;
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      scanf("%c", &c);
      board[i][j] = c;
    }
    scanf("%c", &c);
  }

  solution();

  return 0;
}
