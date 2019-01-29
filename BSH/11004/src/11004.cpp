//============================================================================
// Name        : 11004.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

	int N, c;
	int arr[50000];

	scanf("%d %d", &N, &c);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	printf("%d", arr[c - 1]);

	return 0;
}

/*
 priority_queue<int, vector<int>, greater<int> > q;
 int N, c;

 scanf("%d %d", &N, &c);

 int temp;
 for (int i = 0; i < N; i++) {
 scanf("%d", &temp);
 q.push(temp);
 }

 for (int i = 1; i < c; i++)
 q.pop();

 printf("%d", q.top());
 */
