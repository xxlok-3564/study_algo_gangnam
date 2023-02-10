//============================================================================
// Name        : 1929.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, M;
	int prime[1000001];
	cin >> N >> M;

	for (int i = 0; i < 1000001; i++)
		prime[i] = 1;
	prime[0] = 0;
	prime[1] = 0;

	int bound = (int) sqrt(M);

	for (int i = 2; i <= bound; i++) {

		if (prime[i] == 0)
			continue;

		for (int j = i + i; j <= M; j += i)
			prime[j] = 0;

	}

	/* endl 같은 경우 시간을 많이 잡아 먹는다. */

	for (int i = N; i <= M; i++)
		if (prime[i])
			cout << i << "\n";

	return 0;
}
