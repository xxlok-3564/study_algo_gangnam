//============================================================================
// Name        : 2579.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int stair[301];
	int dp[301][2];
	int N;

	cin >> N;

	for(int i = 1; i <= N; i++)
		cin >> stair[i];

	dp[0][0]= 0;
	dp[0][1]=0;

	for(int i = 1; i <= N; i++){
		dp[i][0] = max(dp[i -2][0], dp[i - 2][1]) + stair[i];
		dp[i][1] = dp[i-1][0] + stair[i];
	}

	cout << max(dp[N][0], dp[N][1]) << endl;

	return 0;
}
