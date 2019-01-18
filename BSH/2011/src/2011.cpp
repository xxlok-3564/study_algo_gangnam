//============================================================================
// Name        : 2011.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

	string all;
	int dp[5001][2];
	int len;
	int sub_len1;
	int sub_len2;

	cin >> all;

	len = all.size();

	sub_len2 = 10 * (all[0] - '0') + all[1] - '0';
	sub_len1 = all[1] - '0';

	if(all[0] - '0'){
		dp[0][0] = 1;
		dp[0][1] = 0;
	} else{
		dp[0][0] = 0;
		dp[0][1] = 0;
	}

	if (10 <= sub_len2 && sub_len2 <= 26){
		dp[1][0] = 1;
		dp[1][1] = 1;

		if(sub_len2 % 10 == 0){
			dp[1][0] = 0;
			dp[1][1] = 1;
		}

	}else{
		dp[1][0] = 1;
		dp[1][1] = 0;
	}


	for (int i = 2; i < len; i++) {

		sub_len2 = 10 * (all[i - 1] - '0') + all[i] - '0';
		sub_len1 = all[i] - '0';

		if (0 < sub_len1 && sub_len1 < 10)
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000;
		else
			dp[i][0] = 0;

		if (10 <= sub_len2 && sub_len2 <= 26)
			dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % 1000000;
		else
			dp[i][1] = 0;

	}

	cout << (dp[len - 1][0] + dp[len - 1][1]) % 1000000;

	return 0;
}
