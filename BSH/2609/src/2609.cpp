//============================================================================
// Name        : 2609.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int gcd(int A, int B) {

	int t;

	while (B) {
		t = A % B;
		A = B;
		B = t;
	}

	return A;
}

int main() {

	int A, B;
	cin >> A >> B;

	int gcd_ans = gcd(max(A, B), min(A, B));

	cout << gcd_ans << endl;
	cout << gcd_ans * A / gcd_ans * B / gcd_ans << endl;

	return 0;
}
