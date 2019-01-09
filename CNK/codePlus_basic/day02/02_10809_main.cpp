#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int len = 'z' - 'a' + 1;
  int arr[len];
  fill_n(arr, len, -1);

  string line;
  getline(cin, line);

  for (int i = 0; i < line.size(); i++) {
    int idx = line[i] - 'a';
    if (arr[idx] == -1) arr[idx] = i;
  }

  for (int i = 0; i < len; i++) {
    cout << arr[i] << ' ';
  }

  return 0;
}