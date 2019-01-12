//============================================================================
// Name        : 1463.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[1000001];

	cin >> N;

	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	int min;

	for (int i = 4; i <= N; i++) {

		min = arr[i - 1] + 1;

		if (i % 2 == 0)
			if (arr[i / 2] + 1 < min)
				min = arr[i / 2] + 1;

		if (i % 3 == 0)
			if (arr[i / 3] + 1 < min)
				min = arr[i / 3] + 1;

		arr[i] = min;

	}

	cout << arr[N];

	return 0;
}
