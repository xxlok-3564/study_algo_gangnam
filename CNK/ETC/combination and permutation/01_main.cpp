/*
조합 그리고 순열
https://makefortune2.tistory.com/227
*/

#include <iostream>

using namespace std;

void comb(int*, int set_size, int m, int n, int index) {
  /* 종료 조건 */
  if(set_size == n) {
    Print_set
  }
}

void calC() {
  int m, n;
  cin >> m >> n;

  /* 조합 (Combination) */
  int* set = new int[n];
  /* 순열 (Permutation) */
  int* arr = new int[n];

  for(int i = 0; i < n; i ++) {
    arr[i] = i;
  }

  cout << m << "C" << n << "for Combination -->> " << "\n";
  comb(set, 0, m, n, 0);
  cout << "\n";

  cout << m << "H" << n << "for Repeated Combination -->> " << "\n";
  r_comb(set, 0, m, n, 0);
  cout << "\n";

  cout << m << "P" << n << "for Permutation -->> " << "\n";
  perm(arr, 0, m, n);
  cout << "\n";

  cout << m << "" << n << "for Repeated Permutation -->> " << "\n";
  r_perm(arr, 0, m, n);
  cout << "\n";

  // 메모리 해제
  delete set;

  return;
}

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
