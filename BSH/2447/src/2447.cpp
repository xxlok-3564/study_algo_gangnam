//============================================================================
// Name        : 2447.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void rec(int start_x, int start_y, int N, vector<vector<bool> > &a) {

	int div3 = N / 3;

	if (div3 == 1) {
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				a[start_y + y][start_x + x] = true;
		a[start_y + 1][start_x + 1] = false;
		return;
	}

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {

			if (x == 1 && y == 1)
				continue;

			rec(start_x + div3 * x, start_y + div3 * y, div3, a);

		}
	}

}

int main() {

	int N;
	vector<vector<bool> > a;
	cin >> N;

	if (N == 1) {
		cout << " " << endl;
		return 0;
	}

	a.resize(N);
	for (int i = 0; i < N; i++)
		a[i].resize(N);

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			a[y][x] = false;

	rec(0, 0, N, a);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (a[y][x])
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}
