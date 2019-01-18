//============================================================================
// Name        : 11054.cpp
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

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int increase[1000][2]; //include, not_include

	increase[0][0] = 0;
	increase[0][1] = 1;

	for (int i = 1; i < N; i++) {

		increase[i][0] = max(increase[i - 1][0], increase[i - 1][1]);

		int max = 0;

		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i] && increase[j][1] > max)
				max = increase[j][1];

		increase[i][1] = max + 1;

	}

	int decrease[1000][2];

	decrease[N - 1][0] = 0;
	decrease[N - 1][1] = 1;

	for (int i = N - 2; i >= 0; i--) {

		decrease[i][0] = max(decrease[i + 1][0], decrease[i + 1][1]);

		int max = 0;

		for (int j = i + 1; j < N; j++)
			if (arr[j] < arr[i] && decrease[j][1] > max)
				max = decrease[j][1];

		decrease[i][1] = max + 1;

	}

	int max = increase[0][1] + decrease[0][1] - 1;
	for (int i = 0; i < N; i++)
		if (increase[i][1] + decrease[i][1] - 1 > max)
			max = increase[i][1] + decrease[i][1] - 1;

	cout << max;

	return 0;
}
