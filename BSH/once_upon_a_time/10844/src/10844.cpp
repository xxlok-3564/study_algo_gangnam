//============================================================================
// Name        : 10844.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define ll long long
using namespace std;

int main() {

	ll arr[100][10];
	int digit;
	cin >> digit;

	arr[0][0] = 0;
	for (int i = 1; i < 10; i++)
		arr[0][i] = 1;

	for (int n = 1; n < digit; n++) {
		for (int end = 0; end < 10; end++) {

			int temp = 0;
			if (end - 1 >= 0)
				temp += arr[n - 1][end - 1];

			if (end + 1 < 10)
				temp += arr[n - 1][end + 1];

			arr[n][end] = temp % 1000000000;

		}
	}

	ll ans = 0;

	for (int i = 0; i < 10; i++)
		ans += arr[digit - 1][i];

	ans %= 1000000000;

	cout << ans;

	return 0;
}
