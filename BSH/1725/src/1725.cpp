//============================================================================
// Name        : 1725.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_INT 0x7fffffff

using namespace std;

int init_tree(vector<int>& arr, vector<int>& tree, int node_number,
		int arr_left, int arr_right) {

	if (arr_right - arr_left == 0)
		return tree[node_number] = arr[arr_left];

	return tree[node_number] = min(
			init_tree(arr, tree, node_number * 2, arr_left,
					(arr_left + arr_right) / 2),
			init_tree(arr, tree, node_number * 2 + 1,
					(arr_left + arr_right) / 2 + 1, arr_right));

}

int query(vector<int>& tree, int node, int node_l, int node_r, int range_l,
		int range_r) {

	if (range_l > node_r || range_r < node_l)
		return MAX_INT;

	if (range_l <= node_l && node_r <= range_r)
		return tree[node];

	return min(
			query(tree, node * 2, node_l, (node_l + node_r) / 2, range_l,
					range_r),
			query(tree, node * 2 + 1, (node_l + node_r) / 2 + 1, node_r,
					range_l, range_r));

}

int main() {

	int N;
	vector<int> arr(100000);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int tree_height = (int) ceil(log2(N));
	int num_node = (1 << (tree_height + 1));
	vector<int> tree(num_node, MAX_INT);
	init_tree(arr, tree, 1, 0, N - 1);

	cout << query(tree, 1, 0, N - 1, 0, 1);

	return 0;
}
