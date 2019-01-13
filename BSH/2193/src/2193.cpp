//============================================================================
// Name        : 2193.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define ll long long
using namespace std;

int main() {
	ll end0[90];
	ll end1[90];
	int digit;

	end0[0] = 0;
	end0[1] = 1;
	end0[2] = 1;

	end1[0] = 1;
	end1[1] = 0;
	end1[2] = 1;

	cin >> digit;

	for (int i = 3; i < digit; i++) {
		end0[i] = end0[i - 1] + end1[i - 1];
		end1[i] = end0[i - 1];
	}

	cout << end0[digit - 1] + end1[digit - 1];

	return 0;
}
