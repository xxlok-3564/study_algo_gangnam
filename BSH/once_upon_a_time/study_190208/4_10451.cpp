//============================================================================
// Name        : 10451.cpp
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

	int T;
	int N;
	int arr[1001];
	int visit[1001];
	queue<int> q;
	int temp;
	int ans = 0;

	scanf("%d", &T);

	for (int test = 0; test < T; test++) {

		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
			scanf("%d", arr + i);

		for (int i = 0; i < 1001; i++)
			visit[i] = 0;

		ans = 0;
		for (int i = 1; i <= N; i++) {

			if (visit[i])
				continue;
			ans += 1;

			int start = i;

			q.push(start);
			visit[start] = 1;

			while (!q.empty()) {
				temp = q.front();
				q.pop();

				if (!visit[arr[temp]]) {
					visit[arr[temp]] = 1;
					q.push(arr[temp]);
				}

			}

		}

		cout << ans << endl;

	}

	return 0;
}
