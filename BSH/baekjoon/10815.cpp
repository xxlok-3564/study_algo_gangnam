//============================================================================
// Name        : 10815.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
	return a.first < b.first;
}

int main() {
	int arr[500000];
	int search_list[500000];
	map<int, int> find_list;
	int N, M;
	int temp;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		arr[i] = temp;
	}
	//O(N)

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		search_list[i] = temp;
		find_list.insert(make_pair(temp, 0));
	}
	//O(MlogM)

	for (int i = 0; i < N; i++)
		find_list[arr[i]] += 1;
	//O(N)

	for (int i = 0; i < M; i++)
		printf("%d ", find_list[search_list[i]]);
	//O(M)

	//N + MlogM + (N + M)

	return 0;
}
