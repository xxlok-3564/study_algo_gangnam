//============================================================================
// Name        : 11724.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

void init_board(int board[1001][1001], int visit[1001]) {
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			board[i][j] = 0;

	for (int i = 0; i < 1001; i++)
		visit[i] = 0;
}

int main() {

	int N, M;
	int board[1001][1001];
	int visit[1001];

	cin >> N >> M;	// N은 점 갯수, M은 선 갯

	init_board(board, visit);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		board[a][b] = board[b][a] = 1;
	}

	queue<int> q;
	int ans = 0;
	int temp;

	for (int root = 1; root <= N; root++) {

		if (visit[root])
			continue;

		ans++;

		q.push(root);
		visit[root] = 1;

		while (!q.empty()) {

			temp = q.front();
			q.pop();

			for (int child = 1; child <= N; child++)
				if (!visit[child] && board[temp][child]) {
					q.push(child);
					visit[child] = 1;
				}

		}

	}

	cout << ans;

	return 0;
}
