//============================================================================
// Name        : 1707.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int K;
	int V, E;
	vector<int> vertex[20001];
	int visit[20001];
	queue<int> q;
	int from;
	int fail = 0;

	scanf("%d", &K);

	int x, y;
	for (int test = 0; test < K; test++) {

		scanf("%d %d", &V, &E);

		fail = 0;
		for (int i = 1; i <= V; i++) {
			vertex[i].clear();
			visit[i] = 0;
		}

		for (int i = 0; i < E; i++) {
			scanf("%d %d", &x, &y);
			vertex[x].push_back(y);
			vertex[y].push_back(x);
		}

		for (int i = 1; i <= V; i++) {

			if (visit[i])
				continue;

			while (!q.empty())
				q.pop();

			q.push(i);
			visit[i] = 1;

			while (!q.empty()) {
				from = q.front();
				q.pop();
				for (unsigned j = 0; j < vertex[from].size(); j++) {

					if (visit[vertex[from][j]] == 0) {
						visit[vertex[from][j]] = 3 - visit[from];
						q.push(vertex[from][j]);
					} else if (visit[vertex[from][j]] == visit[from]) {
						fail = 1;
						break;
					}

				}
				if (fail)
					break;
			}

			if (fail)
				break;

		}

		if (fail)
			printf("NO\n");
		else
			printf("YES\n");

	}

	return 0;
}
