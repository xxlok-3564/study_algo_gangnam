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
	int dp[1000];
	int max;

	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> arr[i];

	dp[0] = arr[0];

	for(int i = 1; i < N; i++){
		int max = 0;
		int left_idx = 0;
		int right_idx = i - 1;
		while(left_idx <= right_idx){
			if(max < dp[left_idx] + dp[right_idx])
				max = dp[left_idx] + dp[right_idx];
			left_idx++;
			right_idx--;
		}
		if(max < arr[i])
			max = arr[i];

		dp[i] = max;

	}

	cout << dp[N - 1];

	return 0;
}
