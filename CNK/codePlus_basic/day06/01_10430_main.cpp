/*
나머지
https://www.acmicpc.net/problem/10430
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int a, b, c;
  cin >> a >> b >> c;

  cout << (a+b)%c << '\n';
  cout << (a+b)%c << '\n';
  cout << (a*b)%c << '\n';
  cout << (a*b)%c << '\n';

  return 0;
}
