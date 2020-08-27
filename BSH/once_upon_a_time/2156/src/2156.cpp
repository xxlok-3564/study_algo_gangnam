//============================================================================
// Name        : 2156.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int arr[10001];
	int n;
	int dp[10000][3]; // 안먹는걸로 끝나는 거, 첫번째로 먹는 걸로 끝나는 거, 두번 째로 먹는걸로 끝나는 거

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0][0] = 0;
	dp[0][1] = arr[0];
	dp[0][2] = 0;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i-1][2]));
		dp[i][1] = dp[i-1][0] + arr[i];
		dp[i][2] = dp[i-1][1] + arr[i];
	}

	cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << endl;

	return 0;
}
