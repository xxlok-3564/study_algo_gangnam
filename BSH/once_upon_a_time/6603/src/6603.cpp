//============================================================================
// Name        : 6603.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void rec(int arr[13], int print_arr[6], int start_idx, int depth, int N) {

	for (int idx = start_idx; idx < N; idx++) {

		print_arr[depth] = arr[idx];

		if (depth == 5) {
			for (int i = 0; i < 6; i++)
				cout << print_arr[i] << " ";
			cout << endl;
		}

		rec(arr, print_arr, idx + 1, depth + 1, N);

	}

}

int main() {

	int N;
	int arr[13];
	int print_arr[13];

	while (1) {

		cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		rec(arr, print_arr, 0, 0, N);

		cout << endl;
	}

	return 0;
}
