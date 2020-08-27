//============================================================================
// Name        : 4883.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define ll long long
using namespace std;

ll arr[100001][3];
ll dp[100001][3];

int main() {

	int N;
	for (int test = 1;; test++) {

		cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

		dp[1][0] = arr[0][1] + arr[1][0];
		dp[1][1] = min(min(arr[0][1], arr[0][1] + arr[0][2]), arr[0][1] + arr[1][0]) + arr[1][1];
		dp[1][2] = min(min(arr[0][1], arr[0][1] + arr[0][2]),
				min(arr[0][1] + arr[1][1], arr[0][1] + arr[0][2] + arr[1][1]))
				+ arr[1][2];

		for (int i = 2; i < N; i++) {

			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1])
					+ arr[i][0];

			dp[i][1] = min(min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]),
					dp[i][0]) + arr[i][1];

			dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]), dp[i][1])
					+ arr[i][2];

		}

		cout << test << ". " << dp[N - 1][1] << endl;

	}

	return 0;
}
