/*
채점
https://www.acmicpc.net/problem/6989
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  printf("%3d\n", n);
  long long *scores = new long long[n];
  for (int i = 0; i < n; i++) {
    cin >> scores[i];
    printf("%3d ", scores[i]);
  }
  printf("\n");
  long long piv_score;
  cin >> piv_score;
  printf("%3d\n", piv_score);

  long long **dp_2 = new long long *[n];  // 누적총점
  vector<vector<long long> > dp_3;
  for (int i = 0; i < n; i++) {
    dp_2[i] = new long long[n];
    fill_n(dp_2[i], n, 0);
  }

  // vector<long long> tots;
  for (int i = 0; i < n; i++) {
    dp_2[i][i] = scores[i];
    vector<long long> vec;

    for (int j = i + 1; j < n; j++) {
      dp_2[i][j] = dp_2[i][j - 1] + dp_2[i][j - 1] + scores[j];
      // if (dp_2[i][j] >= piv_score)
      //   tots.push_back(dp_2[i][j]);  // 경우의 수 추가
    }

    // dp_3 넣을 값들
    for (int j = 0; j <= i - 2; j++) {
      long long sel_point = dp_2[j][i - 2];
      vec.push_back(sel_point);
      for (int k = 1; k < dp_3[j].size(); k++) {
        vec.push_back(dp_3[j][k] + sel_point);
      }
    }
    dp_3.push_back(vec);
  }

  // for (int i = 2; i < n; i++) {
  //   long long temp_point = dp_2[i][n - 1];
  //   for (long long point : dp_3[i]) {
  //     if (point != 0 && temp_point + point >= piv_score)
  //       tots.push_back(temp_point + point);  // 경우의 수 추가
  //   }
  // }

  /* dp 출력 */
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     printf("%3d ", dp_1[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%3d ", dp_2[i][j]);
    }
    printf("\n");
  }
  // printf("\n");
  // for (int i = 0; i < n; i++) {
  //   for (long long point : dp_3[i]) {
  //     printf("%4d ", point);
  //   }
  //   printf("\n");
  // }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%3d, ", dp_3[i].size());
  }
  printf("\n");
  // sort(tots.begin(), tots.end());
  // for(int i = 0; i < tots.size(); i++) {
  //   printf("%3d, ", tots[i]);
  // }
  // printf("\n");
  // if (tots.size() != 0) {
  //   long long rec = piv_score - 1;
  //   for (int i = 0; i < tots.size(); i++) {
  //     if (tots[i] - rec > 1) {
  //       rec += 1;
  //       break;
  //     }
  //     rec = tots[i];
  //   }
  //   cout << rec;
  // } else {
  //   cout << piv_score;
  // }

  return 0;
}