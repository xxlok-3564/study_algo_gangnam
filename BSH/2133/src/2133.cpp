//============================================================================
// Name        : 2133.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define ll long long
using namespace std;

int main() {
	ll arr[30][10];
	int N;
	cin >> N;

	for (int i = 0; i < 10; i++)
		arr[0][i] = 0;

	arr[0][0] = 1;
	arr[0][2] = 1;
	arr[0][4] = 1;

	for (int i = 1; i < N; i++) {
		arr[i][0] = arr[i - 1][1] + arr[i - 1][3] + arr[i - 1][5];
		arr[i][1] = arr[i - 1][0] + arr[i - 1][7];
		arr[i][2] = arr[i - 1][1] + arr[i - 1][3] + arr[i - 1][5];
		arr[i][3] = arr[i - 1][2];
		arr[i][4] = arr[i - 1][1] + arr[i - 1][3] + arr[i - 1][5];
		arr[i][5] = arr[i - 1][4] + arr[i - 1][9];
		arr[i][6] = arr[i - 1][0] + arr[i - 1][7];
		arr[i][7] = arr[i - 1][6];
		arr[i][8] = arr[i - 1][4] + arr[i - 1][9];
		arr[i][9] = arr[i - 1][8];
	}

	cout << arr[N - 1][1] + arr[N - 1][3] + arr[N - 1][5];

	return 0;
}
