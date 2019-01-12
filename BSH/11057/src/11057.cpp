//============================================================================
// Name        : 11057.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define ll long long
using namespace std;

int main() {

	int arr[1000][10];
	int digit;
	cin >> digit;

	for (int i = 0; i < 10; i++)
		arr[0][i] = 1;

	ll temp = 0;
	for (int n = 1; n < digit; n++) {
		for (int end = 0; end < 10; end++) {
			for(int check = end; check < 10; check++)
				temp += arr[n - 1][check];
			arr[n][end] = temp % 10007;
			temp = 0;
		}
	}

	ll ans = 0;

	for (int i = 0; i < 10; i++)
		ans += arr[digit - 1][i];

	cout << ans % 10007;

	return 0;
}
