//============================================================================
// Name        : 14490.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int a, b;
	char c;

	cin >> a >> c >> b;

	int m = min(a, b);

	for (int i = 2; i <= m; i++) {

		while ((a % i == 0) && (b % i == 0)) {
			a /= i;
			b /= i;
		}

	}

	cout << a << ":" << b;

	return 0;
}
