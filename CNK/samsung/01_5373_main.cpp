/*
큐빙
https://www.acmicpc.net/problem/5373
*/
#include <iostream>
#include <map>

using namespace std;

map<char, char **> sides;
map<char, char> colors = {{'U', 'w'}, {'D', 'y'}, {'F', 'r'},
                          {'B', 'o'}, {'L', 'g'}, {'R', 'b'}};
map<char, char>::iterator it;

// 큐브 초기화
void init_cubing() {
  for (it = colors.begin(); it != colors.end(); it++) {
    char side = it->first;
    char color = it->second;
    sides[side] = new char *[3];
    for (int i = 0; i < 3; i++) {
      sides[side][i] = new char[3];
      fill_n(sides[side][i], 3, color);
    }
  }
}

void swap(char &a1, char &a2, char &a3, char b1, char b2, char b3) {
  a1 = b1;
  a2 = b2;
  a3 = b3;
}

void self_rotation_cubing(char sel) {
  char b1 = sides[sel][0][0];
  char b2 = sides[sel][0][1];
  char b3 = sides[sel][0][2];
  swap(sides[sel][0][0], sides[sel][0][1], sides[sel][0][2],
       sides[sel][2][0], sides[sel][1][0], sides[sel][0][0]);
  swap(sides[sel][2][0], sides[sel][1][0], sides[sel][0][0],
       sides[sel][2][2], sides[sel][2][1], sides[sel][2][0]);
  swap(sides[sel][2][2], sides[sel][2][1], sides[sel][2][0],
       sides[sel][0][2], sides[sel][1][2], sides[sel][2][2]);
  swap(sides[sel][0][2], sides[sel][1][2], sides[sel][2][2], b1, b2, b3);
}

// 선택된 큐브 sel을 dir방향으로
void rotation_cubing(char sel) {
  char a1, a2, a3;
  
  switch (sel) {
    case 'U':
      a1 = sides['B'][0][0];
      a2 = sides['B'][0][1];
      a3 = sides['B'][0][2];
      swap(sides['B'][0][0], sides['B'][0][1], sides['B'][0][2],
           sides['L'][0][0], sides['L'][0][1], sides['L'][0][2]);
      swap(sides['L'][0][0], sides['L'][0][1], sides['L'][0][2],
           sides['F'][0][0], sides['F'][0][1], sides['F'][0][2]);
      swap(sides['F'][0][0], sides['F'][0][1], sides['F'][0][2],
           sides['R'][0][0], sides['R'][0][1], sides['R'][0][2]);
      swap(sides['R'][0][0], sides['R'][0][1], sides['R'][0][2], a1, a2, a3);
      break;

    case 'D':
      a1 = sides['F'][2][0];
      a2 = sides['F'][2][1];
      a3 = sides['F'][2][2];
      swap(sides['F'][2][0], sides['F'][2][1], sides['F'][2][2],
           sides['L'][2][0], sides['L'][2][1], sides['L'][2][2]);
      swap(sides['L'][2][0], sides['L'][2][1], sides['L'][2][2],
           sides['B'][2][0], sides['B'][2][1], sides['B'][2][2]);
      swap(sides['B'][2][0], sides['B'][2][1], sides['B'][2][2],
           sides['R'][2][0], sides['R'][2][1], sides['R'][2][2]);
      swap(sides['R'][2][0], sides['R'][2][1], sides['R'][2][2], a1, a2, a3);
      break;

    case 'F':
      a1 = sides['U'][2][0];
      a2 = sides['U'][2][1];
      a3 = sides['U'][2][2];
      swap(sides['U'][2][0], sides['U'][2][1], sides['U'][2][2],
           sides['L'][2][2], sides['L'][1][2], sides['L'][0][2]);
      swap(sides['L'][2][2], sides['L'][1][2], sides['L'][0][2],
           sides['D'][0][2], sides['D'][0][1], sides['D'][0][0]);
      swap(sides['D'][0][2], sides['D'][0][1], sides['D'][0][0],
           sides['R'][0][0], sides['R'][1][0], sides['R'][2][0]);
      swap(sides['R'][0][0], sides['R'][1][0], sides['R'][2][0], a1, a2, a3);
      break;
    // 여기까지... 힘들어,,,
    case 'B':
      a1 = sides['U'][0][0];
      a2 = sides['U'][0][1];
      a3 = sides['U'][0][2];
      swap(sides['U'][0][0], sides['U'][0][1], sides['U'][0][2],
           sides['R'][0][2], sides['R'][1][2], sides['R'][2][2]);
      swap(sides['R'][0][2], sides['R'][1][2], sides['R'][2][2],
           sides['D'][2][2], sides['D'][2][1], sides['D'][2][0]);
      swap(sides['D'][2][2], sides['D'][2][1], sides['D'][2][0],
           sides['L'][2][0], sides['L'][1][0], sides['L'][0][0]);
      swap(sides['L'][2][0], sides['L'][1][0], sides['L'][0][0], a1, a2, a3);
      break;

    case 'L':
      a1 = sides['U'][0][0];
      a2 = sides['U'][1][0];
      a3 = sides['U'][2][0];
      swap(sides['U'][0][0], sides['U'][1][0], sides['U'][2][0],
           sides['B'][2][2], sides['B'][1][2], sides['B'][0][2]);
      swap(sides['B'][2][2], sides['B'][1][2], sides['B'][0][2],
           sides['D'][0][0], sides['D'][1][0], sides['D'][2][0]);
      swap(sides['D'][0][0], sides['D'][1][0], sides['D'][2][0],
           sides['F'][0][0], sides['F'][1][0], sides['F'][2][0]);
      swap(sides['F'][0][0], sides['F'][1][0], sides['F'][2][0], a1, a2, a3);
      break;

    case 'R':
      a1 = sides['U'][0][2];
      a2 = sides['U'][1][2];
      a3 = sides['U'][2][2];
      swap(sides['U'][0][2], sides['U'][1][2], sides['U'][2][2],
           sides['F'][0][2], sides['F'][1][2], sides['F'][2][2]);
      swap(sides['F'][0][2], sides['F'][1][2], sides['F'][2][2],
           sides['D'][0][2], sides['D'][1][2], sides['D'][2][2]);
      swap(sides['D'][0][2], sides['D'][1][2], sides['D'][2][2],
           sides['B'][2][0], sides['B'][1][0], sides['B'][0][0]);
      swap(sides['B'][2][0], sides['B'][1][0], sides['B'][0][0], a1, a2, a3);
      break;

    default:
      break;
  }
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    init_cubing();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      string cmd;
      cin >> cmd;
      cin.ignore();
      if(cmd[1] == '+') {
        rotation_cubing(cmd[0]);
        self_rotation_cubing(cmd[0]);
      } else {
        rotation_cubing(cmd[0]);
        self_rotation_cubing(cmd[0]);
        rotation_cubing(cmd[0]);
        self_rotation_cubing(cmd[0]);
        rotation_cubing(cmd[0]);
        self_rotation_cubing(cmd[0]);        
      }
      
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << sides['U'][i][j];
      }
      cout << '\n';
    }
  }

  return 0;
}
