/*
블록 게임
https://programmers.co.kr/learn/courses/30/lessons/42894
*/
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;

int dir[5][6][2] = {{{0, 0}, {1, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 2}},
                    {{0, 0}, {-1, 0}, {-1, 1}, {0, 1}, {0, 2}, {-1, 2}},
                    {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 0}, {2, 1}},
                    {{0, 0}, {0, 1}, {-1, 1}, {-1, 0}, {-2, 0}, {-2, 1}},
                    {{0, 0}, {0, 1}, {-1, 1}, {1, 1}, {1, 0}, {-1, 0}}};

void print_arr(vector<vector<int>> &arr) {
  int n = arr.size();
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%5d ", arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void print_pair(vector<pair<int, int>> &arr) {
  int n = arr.size();  
  for (int i = 0; i < n; i++) {
    printf("<%d, %d> ", arr[i].first, arr[i].second);
  }
  printf("\n\n");
}

void fill_darks(vector<vector<int>> &board, vector<vector<int>> &darks) {
  int n = board.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[j][i] == 0) {
        darks[j][i] = 1;
      } else {
        break;
      }
    }
  }  
}

void fill_nedded(vector<vector<int>> &board,
                 map<int, vector<pair<int, int>>> &needed) {
  int n = board.size();
  // 이놈이 구현 하기 싫어 ㅠㅠ
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[j][i] != 0) {
        if (needed.find(board[j][i]) == needed.end()) {
          int is_rect = 0;
          int etc_cnt = 0;   // 2개
          int self_cnt = 0;  // 4개
          for (int k = 0; k < 5; k++) {
            is_rect = k;
            etc_cnt = 0;
            self_cnt = 0;
            for (int d = 0; d < 6; d++) {
              int tmp_x = j + dir[k][d][0];
              int tmp_y = i + dir[k][d][1];

              if (tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < n) {
                // 범위에 들어가는지 체크
                if (board[tmp_x][tmp_y] == board[j][i]) {
                  // 자신의 블럭일 경우
                  self_cnt += 1;
                } else {
                  // 0이나 다른 종류의 블럭일경우
                  etc_cnt += 1;
                }
              }
            }

            if (etc_cnt == 2 && self_cnt == 4) {
              vector<pair<int, int>> vv(6);
              for (int d = 0; d < 6; d++) {
                int tmp_x = j + dir[is_rect][d][0];
                int tmp_y = i + dir[is_rect][d][1];
                vv[d] = make_pair(tmp_x, tmp_y);
              }
              needed[board[j][i]] = vv;
              break;
            }
          }
        }
      }
    }
  }
}

int solution(vector<vector<int>> board) {
  // 정답
  int answer = 0;

  // 각 블럭이 직사각형이 되기 위해서 필요한 곳 needed에 기록
  map<int, vector<pair<int, int>>> needed;
  fill_nedded(board, needed);

  // 검정블럭을 채울수 있는지 여부
  int n = board.size();
  vector<vector<int>> darks(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      darks[i].push_back(0);
    }
  }


  bool is_change;
  int cnt_r;
  // 더이상 변화가 없을때까지 반복
  // 블럭을 채울수 있는지 여부 darks에 기록
  do {
    is_change = false;
    
    fill_darks(board, darks);

    for (auto it = needed.begin(); it != needed.end(); it++) {
      int key = it->first;
      auto vv = it->second;
      cnt_r = 0;

      // 지울수 있는지 확인
      for (int i = 0; i < 6; i++) {
        int tmp_x = vv[i].first;
        int tmp_y = vv[i].second;
        if (board[tmp_x][tmp_y] != key && darks[tmp_x][tmp_y] == 1) {
          cnt_r += 1;
        }
      }

      // 지울수 있다면...
      if (cnt_r == 2) {
        for (int i = 0; i < 6; i++) {
          int tmp_x = vv[i].first;
          int tmp_y = vv[i].second;
          board[tmp_x][tmp_y] = 0;
        }
        /*
          이부분에서 오류가 나는데...
        */
        // needed.erase(key);
        answer += 1;
        is_change = true;

        // print_arr(board);        
      }
    }

  } while (is_change);

  // printf("ans :: %d\n", answer);

  return answer;
}

int main(int argc, char const *argv[]) {
  int n, num;
  scanf("%d", &n);
  vector<vector<int>> board(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &num);
      board[i].push_back(num);
    }
  }

  solution(board);

  return 0;
}
