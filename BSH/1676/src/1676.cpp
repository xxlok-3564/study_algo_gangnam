//============================================================================
// Name        : 1676.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int N;
	cin >> N;

	int num2 = 0;
	int num5 = 0;
	for (int i = 1; i <= N; i++) {
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

	cout << min(num2, num5);

	return 0;
}
