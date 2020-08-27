//============================================================================
// Name        : 9095.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define ll long long
using namespace std;

int main() {

	ll arr[11];
	int T, N;

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 11; i++)
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;

		cout << arr[N] << '\n';
	}

	return 0;
}
