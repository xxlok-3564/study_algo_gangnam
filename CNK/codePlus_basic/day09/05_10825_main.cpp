/*
국영수
https://www.acmicpc.net/problem/10825
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct Student {
  string name;
  int ko, en, mt;
};

bool cmp(const Student &s1, const Student &s2) {
  // if (s1.ko > s2.ko) {
  //   return true;
  // } else if (s1.ko == s2.ko) {
  //   if (s1.en < s2.en) {
  //     return true;
  //   } else if (s1.en == s2.en) {
  //     if (s1.mt > s2.mt) {
  //       return true;
  //     } else if (s1.mt == s2.mt) {
  //       return s1.name < s2.name;
  //     } else {
  //       return false;
  //     }
  //   } else {
  //     return false;
  //   }
  // } else {
  //   return false;
  // }
  return make_tuple(-s1.ko, s1.en, -s1.mt, s1.name) < make_tuple(-s2.ko, s2.en, -s2.mt, s2.name);
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  vector<Student> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].name;
    cin >> v[i].ko;
    cin >> v[i].en;
    cin >> v[i].mt;
  }

  sort(v.begin(), v.end(), cmp);
  for(int i = 0; i < n; i++) {
    cout << v[i].name << "\n";
  }

  return 0;
}
