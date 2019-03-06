//============================================================================
// Name        : 2263.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int idx_arr[100001][2];
int in_arr[100001];
int post_arr[100001];

void rec(int in_left, int in_right, int post_left, int post_right) {

	if (in_right < in_left || post_right < post_left)
		return;

	cout << post_arr[post_right] << " ";

	int in_idx = idx_arr[post_arr[post_right]][0];

	int num_left = in_idx - in_left;
	int num_right = in_right - in_idx;

	rec(in_left, in_left + num_left - 1, post_left, post_left + num_left - 1);

	rec(in_idx + 1, in_idx + num_right, post_left + num_left,
			post_left + num_left + num_right - 1);

}

int main() {

	int N;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> in_arr[i];
		idx_arr[in_arr[i]][0] = i;
	}

	for (int i = 1; i <= N; i++) {
		cin >> post_arr[i];
		idx_arr[post_arr[i]][1] = i;
	}

	rec(1, N, 1, N);

	return 0;
}
