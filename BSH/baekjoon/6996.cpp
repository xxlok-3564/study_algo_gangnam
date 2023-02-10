//============================================================================
// Name        : 6996.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int T;
	cin >> T;

	for (int test = 0; test < T; test++) {
		string A, B;
		int alpha[26];
		cin >> A >> B;

		for (int i = 0; i < 26; i++)
			alpha[i] = 0;

		for (unsigned i = 0; i < A.size(); i++)
			alpha[A[i] - 'a'] += 1;

		for (unsigned i = 0; i < B.size(); i++)
			alpha[B[i] - 'a'] -= 1;

		int fail = 0;
		for (int i = 0; i < 26; i++)
			if (alpha[i] != 0)
				fail = 1;

		cout << A << " & " << B << " are";

		if (fail)
			cout << " NOT";

		cout << " anagrams.\n";

	}

	return 0;
}
