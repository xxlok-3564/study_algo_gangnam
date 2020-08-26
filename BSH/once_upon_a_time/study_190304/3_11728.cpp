//============================================================================
// Name        : 11728.cpp
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
	int N, M;
	vector<int> A;
	vector<int> B;

	cin >> N >> M;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.push_back(temp);
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		B.push_back(temp);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	vector<int>::iterator A_iter = A.begin();
	vector<int>::iterator B_iter = B.begin();

	while (A_iter != A.end() && B_iter != B.end()) {

		if (*A_iter >= *B_iter) {
			cout << *B_iter << " ";
			B_iter++;
		} else {
			cout << *A_iter << " ";
			A_iter++;
		}

	}

	if (A_iter == A.end()) {
		while (B_iter != B.end()) {
			cout << *B_iter << " ";
			B_iter++;
		}
	}

	if (B_iter == B.end()) {
		while (A_iter != A.end()) {
			cout << *A_iter << " ";
			A_iter++;
		}
	}

	return 0;
}
