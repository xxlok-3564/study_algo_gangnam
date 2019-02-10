//============================================================================
// Name        : 2178.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

struct coord {
	int x;
	int y;
	int step;
};

int diff_x[4] = { -1, 0, 1, 0 };
int diff_y[4] = { 0, -1, 0, 1 };

bool in_boundary(coord a, int N, int M) {

	return (0 <= a.x && a.x < M && 0 <= a.y && a.y < N) ? true : false;
}

int main() {

	bool board[100][100];
	bool visit[100][100];
	int N, M; // N은 행, M은 열
	char c;

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> c;
			board[y][x] = c == '1' ? true : false;
			visit[y][x] = false;
		}
	}

	coord current;

	queue<coord> q;

	q.push( { 0, 0, 1 });
	visit[0][0] = true;

	while (!q.empty()) {

		current = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
			if (in_boundary( { current.x + diff_x[i], current.y + diff_y[i] },
					N, M)
					&& !visit[current.y + diff_y[i]][current.x + diff_x[i]]
					&& board[current.y + diff_y[i]][current.x + diff_x[i]]) {

				visit[current.y + diff_y[i]][current.x + diff_x[i]] = true;
				q.push(
						{ current.x + diff_x[i], current.y + diff_y[i],
								current.step + 1 });

				if (current.x + diff_x[i] == M - 1
						&& current.y + diff_y[i] == N - 1)
					cout << current.step + 1;
			}

	}

	return 0;
}
