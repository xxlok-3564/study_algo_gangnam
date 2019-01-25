//============================================================================
// Name        : 6588.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void prime_set(bool prime[1000001], int prime_list[1000001]) {

	int prime_list_idx = 0;

	for (int i = 1; i < 1000001; i++)
		prime[i] = true;

	prime[0] = false;
	prime[1] = false;

	int boundary = (int) sqrt(1000000);

	for (int i = 2; i <= boundary; i++) {

		if (prime[i] == false)
			continue;

		prime_list[prime_list_idx] = i;
		prime_list_idx++;

		for (int j = i + i; j < 1000001; j += i)
			prime[j] = false;

	}

}

int main() {

	bool prime[1000001];
	int prime_list[1000001];

	prime_set(prime, prime_list);

	while (1) {

		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		int prime_idx = 0;

		while (1) {

			if (prime[n - prime_list[prime_idx]]) {

				printf("%d = %d + %d\n", n, prime_list[prime_idx],
						n - prime_list[prime_idx]);
				break;
			}

			prime_idx++;
		}

	}

	return 0;
}
