//============================================================================
// Name        : 11047.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int N, K;
	int money[10];
	int ans = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> money[i];

	int idx = N - 1;
	while (K) {

		while (money[idx] > K)
			idx--;

		ans += (K / money[idx]);
		K = K - (K / money[idx] * money[idx]);

	}
	cout << ans;

	return 0;
}
