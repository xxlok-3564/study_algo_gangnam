//============================================================================
// Name        : 2225.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

long long recursive(long long arr[201][201], int N, int K) {

	if (K == 1)
		return arr[N][K] = 1;

	if (N == 0)
		return arr[N][K] = 1;

	if (arr[N][K] != -1)
		return arr[N][K];

	long long sum = 0;

	return sum = (recursive(arr, N, K - 1) + recursive(arr, N - 1, K))
			% 1000000000;

}

int main() {

	int N, K;
	long long arr[201][201];

	for (int i = 0; i < 201; i++)
		for (int j = 0; j < 201; j++)
			arr[i][j] = -1;

	cin >> N >> K;

	for (int i = 0; i <= N; i++)
		arr[1][i] = 1;

	for (int i = 2; i <= K; i++) {
		arr[i][0] = 1;
		for (int j = 1; j <= N; j++)
			arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % 1000000000;
	}

	cout << arr[K][N];

	return 0;
}
