//============================================================================
// Name        : 9613.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define ll long long
using namespace std;

int gcd(int A, int B) {

	int t;
	while (B) {
		t = A % B;
		A = B;
		B = t;
	}
	//cout << A << " ";
	return A;

}

int main() {

	int T;
	int arr[100];
	cin >> T;

	for (int test = 0; test < T; test++) {
		int N;
		ll sum = 0;
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
				sum += gcd(arr[i], arr[j]);

		cout << sum << endl;
	}

	return 0;
}
