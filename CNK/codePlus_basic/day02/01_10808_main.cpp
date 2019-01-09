#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> vec(26);

  string line;
  getline(cin, line);

  for(int i = 0; i < line.size(); i++) {
    int idx = line[i]-'a';
    vec[idx] += 1;
  }

  for(int i = 0; i < vec.size(); i++) {
    cout << vec[i] << ' ';
  }

  return 0;
}