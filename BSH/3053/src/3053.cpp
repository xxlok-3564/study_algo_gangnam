//============================================================================
// Name        : 3053.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#define PI 3.14159265358979
using namespace std;

int main() {

	int R;
	cin >> R;

	cout << fixed;
	cout.precision(6);
	cout << PI * R * R << endl;
	cout << 2 * (double)R * R << endl;

	return 0;
}
