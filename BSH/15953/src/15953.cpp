//============================================================================
// Name        : 15953.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int f1(int N) {

	if(N == 0)
		return 0;

	int n[6][2] = { { 5000000, 1 }, { 3000000, 2 }, { 2000000, 3 },
			{ 500000, 4 }, { 300000, 5 }, { 100000, 6 } };

	int people = 0;
	for (int i = 0; i < 6; i++) {
		people += n[i][1];
		if (people >= N)
			return n[i][0];
	}

	return 0;
}

int f2(int M) {

	if(M == 0)
		return 0;

	int n[5][2] = { { 5120000, 1 }, { 2560000, 2 }, { 1280000, 4 },
			{ 640000, 8 }, { 320000, 16 } };

	int people = 0;
	for (int i = 0; i < 5; i++) {
		people += n[i][1];
		if (people >= M)
			return n[i][0];
	}

	return 0;
}
int main() {
	int T;
	int N, M;

	cin >> T;

	for (int i = 0; i < T; i++) {

		cin >> N >> M;

		cout << f1(N) + f2(M) << endl;

	}

	return 0;
}
