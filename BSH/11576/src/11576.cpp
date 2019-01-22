//============================================================================
// Name        : 11576.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B;

	int ans[64];
	int num_A[25];
	long long base10 = 0;
	int digit;

	cin >> A >> B;

	cin >> digit;

	for (int i = 0; i < digit; i++)
		cin >> num_A[i];

	// baseA to base10
	long long pos = 1;

	for (int i = digit - 1; i >= 0; i--) {
		base10 += (num_A[i] * pos);
		pos *= A;
	}

	long long where = 0;

	while (base10) {
		ans[where] = base10 % B;
		base10 /= B;
		where++;
	}

	for (int i = where - 1; i >= 0; i--) {
		cout << ans[i];
		if (i != 0)
			cout << " ";
	}
	cout << "\n" << where << '\n';

	return 0;
}
