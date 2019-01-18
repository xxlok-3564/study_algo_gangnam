//============================================================================
// Name        : 9461.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int T;
	cin >> T;

	for(int i = 0; i < T; i++){

		int N;
		long long int arr[103];
		cin >> N;

		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 1;
		arr[3] = 1;
		arr[4] = 2;
		arr[5] = 2;

		for(int j = 6; j <= N; j += 6){

			arr[j] = arr[j - 1] + arr[j - 5];
			arr[j + 1] = arr[j] + arr[j - 4];
			arr[j + 2] = arr[j + 1] + arr[j - 3];
			arr[j + 3] = arr[j + 2] + arr[j - 2];
			arr[j + 4] = arr[j + 3] + arr[j - 1];
			arr[j + 5] = arr[j + 4] + arr[j];

		}

		cout << arr[N] << endl;
	}

	return 0;
}
