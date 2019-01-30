/*
나이순 정렬
https://www.acmicpc.net/problem/10814
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
  int age, join;
  string name;
};

bool cmp(const Student &s1, const Student &s2) {
  if (s1.age < s2.age) {
    return true;
  } else if (s1.age == s2.age) {
    // if(s1.join < s2.join) {
    //   return true;
    // } else {
    //   return false;
    // }
    return s1.join < s2.join;
  } else {
    return false;
  }
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  vector<Student> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].age >> v[i].name;
    v[i].join = i;
  }

  sort(v.begin(), v.end(), cmp);

  for (int i = 0; i < n; i++) {
    cout << v[i].age << " " << v[i].name << "\n";
  }

  return 0;
}
