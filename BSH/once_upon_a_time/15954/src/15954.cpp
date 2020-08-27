//============================================================================
// Name        : 15954.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

ll init(vector<ll> &arr, vector<ll> &tree, int node_number, int start,
		int end) {

	if (start == end)
		return tree[node_number] = arr[start];
	else
		return tree[node_number] = init(arr, tree, 2 * node_number, start,
				(start + end) / 2)
				+ init(arr, tree, 2 * node_number + 1, (start + end) / 2 + 1,
						end);

}

ll sum(vector<ll> &tree, int node_number, int start, int end, int left,
		int right) {

	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node_number];

	return sum(tree, node_number * 2, start, (start + end) / 2, left, right)
			+ sum(tree, node_number * 2 + 1, (start + end) / 2 + 1, end, left,
					right);
}

double get_std(vector<ll> &arr, vector<ll> &tree, int N, int left, int right) {

	double avg = (double) sum(tree, 1, 0, N - 1, left, right)
			/ (right - left + 1);

	double std = 0;

	for (int i = left; i <= right; i++)
		std += ((arr[i] - avg) * (arr[i] - avg));

	return sqrt(std / (right - left + 1));
}

int main() {

	int N, K;
	cin >> N >> K;

	vector<ll> arr(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int tree_height = (int) ceil(log2(N));
	ll total_node = (1 << ((ll) tree_height + 1));

	vector<ll> tree(total_node);

	init(arr, tree, 1, 0, N - 1);

	double ans = get_std(arr, tree, N, 0, K - 1);

	for (int left = 0; left < N - K + 1; left++)
		for (int right = left + K - 1; right < N; right++) {
			double temp = get_std(arr, tree, N, left, right);
			if (ans > temp)
				ans = temp;
		}

	cout.precision(11);
	cout << ans;

	return 0;
}
