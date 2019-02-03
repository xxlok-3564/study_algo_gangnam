//============================================================================
// Name        : 2667.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

int diff_x[4] = { 0, -1, 1, 0 };
int diff_y[4] = { -1, 0, 0, 1 };

int in_boundary(int x, int y, int N) {
	if (x >= 0 && x < N && y >= 0 && y < N)
		return 1;
	return 0;
}

void init_visit(int visit[25][25], int N) {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			visit[y][x] = 0;
}

int main() {

	char c;
	int N;
	int board[25][25];
	int visit[25][25];
	queue<pair<int, int> > q;
	priority_queue<int, vector<int>, greater<int> > pq;
	pair<int, int> current;

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> c;
			board[y][x] = c - '0';
		}
	}

	init_visit(visit, N);
	int town_size = 0;
	int num_town = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (board[y][x] && !visit[y][x]) {
				num_town += 1;
				town_size = 0;

				q.push(make_pair(x, y));
				town_size += 1;
				visit[y][x] = 1;

				while (!q.empty()) {
					current = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						if (in_boundary(current.first + diff_x[i],
								current.second + diff_y[i], N)
								&& !visit[current.second + diff_y[i]][current.first
										+ diff_x[i]]
								&& board[current.second + diff_y[i]][current.first
										+ diff_x[i]]) {
							visit[current.second + diff_y[i]][current.first
									+ diff_x[i]] = 1;
							town_size += 1;
							q.push(
									make_pair(current.first + diff_x[i],
											current.second + diff_y[i]));
						}
					}
				}
				pq.push(town_size);
			}
		}
	}

	cout << num_town << endl;

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}
