//============================================================================
// Name        : 7453.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N), B(N), C(N), D(N);
	vector<int> sum_AB(N * N), sum_CD(N * N);

	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum_AB[i * N + j] = A[i] + B[j];
			sum_CD[i * N + j] = C[i] + D[j];
		}
	}

	sort(sum_CD.begin(), sum_CD.end());

	long long ans = 0;
	for (int i = 0; i < (int)sum_AB.size(); i++) {
		pair<vector<int>::iterator, vector<int>::iterator> a;

		a = equal_range(sum_CD.begin(), sum_CD.end(), sum_AB[i] * -1);

		ans += (a.second - a.first);

	}

	cout << ans;

	return 0;
}
