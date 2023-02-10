//============================================================================
// Name        : 9465.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * 처음에 대각선만 구했더니 안됨. 생각해보니
 * 대각선에서 더하는 경우 뿐만 아니라 추가적으로 더해지는 경우가 존재
 */

#include <iostream>
using namespace std;

int main() {

	int T;
	int n;
	int arr[100001][2];
	int dp[100001][2];

	cin >> T;

	for (int case_num = 0; case_num < T; case_num++) {

		cin >> n;

		for (int i = 1; i <= n; i++)
			cin >> arr[i][0];
		for (int i = 1; i <= n; i++)
			cin >> arr[i][1];

		dp[0][0] = 0;
		dp[0][1] = 0;
		dp[1][0] = arr[1][0];
		dp[1][1] = arr[1][1];

		for (int i = 2; i <= n; i++) {
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + arr[i][0];
			dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + arr[i][1];
		}

		if (dp[n][0] > dp[n][1])
			cout << dp[n][0] << endl;
		else
			cout << dp[n][1] << endl;
	}

	return 0;
}
