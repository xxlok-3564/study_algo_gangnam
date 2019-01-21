#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string solve(long long n, int b) {
  string res = "";
  string temp = "";
  long long rem;

  ostringstream ostr;

  while (n > 0) {
    rem = n % b;
    n /= b;

    if (rem < 10) {
      ostr.str("");
      ostr << rem;
      temp = ostr.str();
    } else {
      char c = 'A' + (rem - 10);
      temp = c;
    }

    res = temp + res;
  }

  return res;
}

int main(int argc, char const *argv[]) {
  long long n;
  int b;

  cin >> n >> b;

  cout << solve(n, b);

  return 0;
}
