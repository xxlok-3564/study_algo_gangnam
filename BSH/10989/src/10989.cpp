//============================================================================
// Name        : 10989.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main() {

	int arr[10001];
	int N;
	int temp;

	cin >> N;

	for (int i = 0; i < 10001; i++)
		arr[i] = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		arr[temp] += 1;
	}

	for (int i = 1; i < 10001; i++)
		if (arr[i])
			for (int j = 0; j < arr[i]; j++)
				printf("%d\n", i);

	return 0;
}
