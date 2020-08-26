//============================================================================
// Name        : 11653.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

 #include <iostream>

 using namespace std;

 int main() {

	 int N;
	 cin >> N;

	 for (int i = 2; i * i <= N; i++) {
		 while (N % i == 0) {
			 cout << i << endl;
			 N /= i;
		 }
	 }

	 if (N > 1)
		 cout << N << endl;

	 return 0;
 }

/*
#include <iostream>
#include <cmath>
using namespace std;

bool prime[10000001];
int prime_list[10000001];
int prime_idx = 0;

void find_prime(bool *prime, int *prime_list, int &prime_idx) {

	for (int i = 0; i < 10000001; i++)
		prime[i] = true;
	prime[0] = false;
	prime[1] = false;

	int boundary = (int) sqrt(10000001);

	for (int j = 2; j <= boundary; j++) {
		if (prime[j] == false)
			continue;
		for (int i = j + j; i < 10000001; i += j)
			prime[i] = false;
	}

	for (int i = 0; i < 10000001; i++)
		if (prime[i]) {
			prime_list[prime_idx] = i;
			prime_idx++;
		}

}

int main() {
	int N;
	cin >> N;

	find_prime(prime, prime_list, prime_idx);

	for (int i = 0; i < prime_idx; i++)
		while (N % prime_list[i] == 0){
			cout << prime_list[i] << '\n';
			N /= prime_list[i];
		}

			return 0;
}
*/
