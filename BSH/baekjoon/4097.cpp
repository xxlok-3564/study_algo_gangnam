//============================================================================
// Name        : 4097.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define ll long long
using namespace std;

ll recursive(ll *arr, ll *dp, int left, int right) {

	if (left == right)
		return dp[left] = arr[left];
	else
		return dp[right] = max(recursive(arr, dp, left, right - 1) + arr[right],
				arr[right]);

}

int main() {

	ll arr[250000];
	ll dp[250000];
	int N;

	while (1) {

		cin >> N;

		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		recursive(arr, dp, 0, N - 1);

		ll max = dp[0];

		for (int i = 0; i < N; i++)
			if (dp[i] > max)
				max = dp[i];

		cout << max << endl;

	}

	return 0;
}
