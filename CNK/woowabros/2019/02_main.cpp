/*
#02
lands	wells	point	result
[ [10, 0, 30, 5], [0, 30, 20, 50], [30, 30, 40, 40] ]	[ [15, 15, 25, 25], [40, 10, 50, 20] ]	[10, 10, 30, 30]	true
[ [0, 0, 20, 10], [10, 20, 20, 40], [30, 0, 50, 20] ]	[ [20, 40, 30, 50], [30, 20, 50, 30] ]	[20, 30, 30, 40]	false
*/
#include <string>
#include <vector>

using namespace std;


bool isOverlab(int x, int y, int x1, int y1, int x2, int y2) {
  if (x > x1 && x < x2 && y > y1 && y < y2) {
    return true;
  } else {
    return false;
  }
}

bool isContain(int x, int y, int x1, int y1, int x2, int y2) {
  if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
    return true;
  } else {
    return false;
  }
}

bool solution(vector<vector<int>> lands, vector<vector<int>> wells,
              vector<int> point) {
  bool answer = true;

  int x1 = point[0];
  int y1 = point[1];
  int x2 = point[2];
  int y2 = point[3];

  // 토지가 겹치는지 check
  for (int i = 0; i < lands.size(); i++) {
    if (isOverlab(lands[i][0], lands[i][3], x1, y1, x2, y2) ||
        isOverlab(lands[i][0], lands[i][1], x1, y1, x2, y2) ||
        isOverlab(lands[i][2], lands[i][3], x1, y1, x2, y2) ||
        isOverlab(lands[i][2], lands[i][1], x1, y1, x2, y2)) {
          return answer = false;
    } else {
      answer = true;
    }
  }

  for(int i = 0; i < wells.size(); i++) {
    if (isContain(wells[i][0], wells[i][3], x1, y1, x2, y2) &&
        isContain(wells[i][0], wells[i][1], x1, y1, x2, y2) &&
        isContain(wells[i][2], wells[i][3], x1, y1, x2, y2) &&
        isContain(wells[i][2], wells[i][1], x1, y1, x2, y2)) {
          return answer = true;
    } else {
      answer = false;
    }
  }

  return answer;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
