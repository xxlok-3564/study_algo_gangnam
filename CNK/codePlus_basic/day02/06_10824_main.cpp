#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string line, buff;
  getline(cin, line);

  stringstream ss(line);
  vector<string> tokens;
  while (ss >> buff) tokens.push_back(buff);

  long long num = stoll(tokens[0] + tokens[1]) + stoll(tokens[2] + tokens[3]);

  cout << num << '\n';

  return 0;
}