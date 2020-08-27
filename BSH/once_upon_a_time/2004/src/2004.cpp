//============================================================================
// Name        : 2004.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int n, m;
	long long num2 = 0;
	long long num5 = 0;

	cin >> n >> m;

	for (int i = m + 1; i <= n; i++) {

		int temp = i;

		while (temp % 2 == 0) {
			num2 += 1;
			temp /= 2;
		}

		while (temp % 5 == 0) {
			num5 += 1;
			temp /= 5;
		}

	}

	for (int i = 1; i <= n - m; i++) {
		int temp = i;

		while (temp % 2 == 0) {
			num2 -= 1;
			temp /= 2;
		}

		while (temp % 5 == 0) {
			num5 -= 1;
			temp /= 5;
		}
	}

	cout << min(num2, num5);

	return 0;
}
