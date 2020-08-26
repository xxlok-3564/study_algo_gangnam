//============================================================================
// Name        : 11055.cpp
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
	int dp[1000][2]; // include, not include

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dp[0][0] = 0;
	dp[0][1] = arr[0];

	for (int i = 1; i < N; i++) {

		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

		int right_idx = i - 1;
		int max = 0;
		while (1) {
			if (right_idx < 0)
				break;

			if (arr[right_idx] < arr[i] && dp[right_idx][1] > max)
				max = dp[right_idx][1];

			right_idx--;
		}

		dp[i][1] = arr[i] + max;

	}

	cout << max(dp[N - 1][0], dp[N - 1][1]);

	return 0;
}
