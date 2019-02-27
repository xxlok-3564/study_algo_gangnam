/*
집합
https://www.acmicpc.net/problem/11723
*/
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

char b[111];
int main(int argc, char const *argv[]) {
  int n = 20;
  int m;
  scanf("%d", &m);
  int s = 0;
  int x;
  while (m--) {
    scanf("%s", b);
    if (!strcmp(b, "add")) {
      scanf("%d", &x);
      x--;
      s = (s | (1 << x));
    } else if (!strcmp(b, "remove")) {
      scanf("%d", &x);
      x--;
      s = (s & ~(1 << x));
    } else if (!strcmp(b, "check")) {
      scanf("%d", &x);
      x--;
      int res = (s & (1 << x));
      if (res) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else if (!strcmp(b, "toggle")) {
      scanf("%d", &x);
      x--;
      s = (s ^ (1 << x));
    } else if (!strcmp(b, "all")) {
      s = (1 << n) - 1;
    } else if (!strcmp(b, "empty")) {
      s = 0;
    }
  }

  return 0;

  // 시간 초과...
  // int n;

  // /* 기본적으로 map 은 less(내림차순)이다. */
  // /* 오름차순 map */
  // map<int, char, greater<int>> m;
  // cin >> n;

  // while (n--) {
  //   string prompt;
  //   cin >> prompt;
  //   if (prompt == "add") {
  //     int n;
  //     cin >> n;
  //     if (m.find(n) == m.end()) {
  //       m[n] = ' ';
  //     }
  //   } else if (prompt == "remove") {
  //     int n;
  //     cin >> n;
  //     if (m.find(n) != m.end()) {
  //       m.erase(n);
  //     }
  //   } else if (prompt == "check") {
  //     int n;
  //     cin >> n;
  //     if (m.find(n) == m.end()) {
  //       cout << 0 << '\n';
  //     } else {
  //       cout << 1 << '\n';
  //     }
  //   } else if (prompt == "toggle") {
  //     int n;
  //     cin >> n;
  //     if (m.find(n) == m.end()) {
  //       m[n] = ' ';
  //     } else {
  //       m.erase(n);
  //     }
  //   } else if (prompt == "all") {
  //     for (int i = 0; i < 20; i++) {
  //       if (m.find(i + 1) == m.end()) {
  //         m[i + 1] = ' ';
  //       }
  //     }
  //   } else if (prompt == "empty") {
  //     m.clear();
  //   }
  // }

  // return 0;
}
