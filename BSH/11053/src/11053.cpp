//============================================================================
// Name        : 11052.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int N;
	int arr[1000];
	int dp[1000][2];
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dp[0][0] = 0;
	dp[0][1] = 1;

	for (int i = 1; i < N; i++) {

		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

		int max = 0;

		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i] && dp[j][1] > max)
				max = dp[j][1];

		dp[i][1] = max + 1;

	}

	cout << max(dp[N - 1][0], dp[N - 1][1]);

	return 0;
}
