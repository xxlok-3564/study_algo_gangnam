//============================================================================
// Name        : 1978.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int maximum = 0;
	int arr[100];
	int N;
	int ans = 0;

	int prime[1001];
	for (int i = 0; i < 1001; i++)
		prime[i] = 1;
	prime[0] = 0;
	prime[1] = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > maximum)
			maximum = arr[i];
	}

	for (int i = 2; i <= maximum; i++) {
		if (prime[i] == 0)
			continue;

		for (int j = i + i; j <= maximum; j += i)
			prime[j] = 0;
	}

	for (int i = 0; i < N; i++)
		ans += prime[arr[i]];

	cout << ans;

	return 0;
}
