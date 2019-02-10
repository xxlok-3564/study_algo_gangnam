//============================================================================
// Name        : 10819.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int ans = 0;

void rec(int idx, int N, int arr[8], bool visit[8], int order[8]) {

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			order[idx] = i;
			if (idx == N - 1) {
				int temp = 0;
				for (int i = 0; i < N - 1; i++)
					temp += abs(arr[order[i]] - arr[order[i + 1]]);
				if (temp > ans)
					ans = temp;
				visit[i] = false;
				return;
			}
			rec(idx + 1, N, arr, visit, order);
			visit[i] = false;
		}
	}

}

int main() {
	int N;
	int arr[8];
	bool visit[8];
	int order[8];
	fill_n(visit, 8, false);
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	rec(0, N, arr, visit, order);

	cout << ans;

	return 0;
}
