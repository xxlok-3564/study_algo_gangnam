//============================================================================
// Name        : 10816.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, M;
	int temp;
	vector<int> card;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		card.push_back(temp);
	}

	sort(card.begin(), card.end());

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		auto a = equal_range(card.begin(), card.end(), temp);
		printf("%ld ", a.second - a.first);
	}

	return 0;
}

/*
 map<int, int> find_list;

 int N, M;

 scanf("%d", &N);

 int temp;
 map<int, int>::iterator idx;
 for (int i = 0; i < N; i++) {
 scanf("%d", &temp);

 if (find_list.find(temp) == find_list.end())
 find_list.insert(make_pair(temp, 1));
 else
 find_list[temp] += 1;
 }
 // O(NlogN)

 scanf("%d", &M);

 for (int i = 0; i < M; i++) {
 scanf("%d", &temp);
 if (find_list.find(temp) == find_list.end())
 printf("0 ");
 else
 printf("%d ", find_list[temp]);
 }
 // O(logM)

 // O(NlogN + logM)
 */
