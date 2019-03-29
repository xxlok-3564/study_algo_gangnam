/**
 * 날짜 계산
 * https://www.acmicpc.net/problem/1476
*/

#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
  int e, s, m;
  scanf("%d %d %d", &e, &s, &m);

  int se, ss, sm;
  se = ss = sm = 1;
  int year = 1;
  while (true) {
    if (se == e && ss == s && sm == m) {
      printf("%d", year);
      return 0;
    } else {
      se = se == 15 ? 1 : se+1;
      ss = ss == 28 ? 1 : ss+1;
      sm = sm == 19 ? 1 : sm+1;
      year += 1;
    }
  }
  

  return 0;
}
