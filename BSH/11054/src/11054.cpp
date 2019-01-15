//============================================================================
// Name        : 11054.cpp
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
	int dp[1000][3];

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dp[0][0] = 0;
	dp[0][1] = 1;
	dp[0][2] = 1;

	for (int i = 1; i < N; i++) {

		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));

		int up = 0;
		int down = 0;

		for (int j = 0; j < i; j++) {

			if (arr[j] < arr[i] && up < dp[j][1])
				up = dp[j][1];

			if (arr[j] > arr[i] && (down < dp[j][2] || up < dp[j][1]))
				down = max(dp[j][1], dp[j][2]);

		}

		dp[i][1] = up + 1;
		dp[i][2] = down + 1;
	}

	cout << max(dp[N - 1][0], max(dp[N - 1][1], dp[N - 1][2]));

	return 0;
}
