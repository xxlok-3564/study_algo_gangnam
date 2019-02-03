//============================================================================
// Name        : 4963.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

int diff_x[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int diff_y[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

void init_visit(int visit[50][50], int row, int col) {
	for (int y = 0; y < row; y++)
		for (int x = 0; x < col; x++)
			visit[y][x] = 0;
}

int in_boundary(int x, int y, int row, int col) {
	if (x >= 0 && x < col && y >= 0 && y < row)
		return 1;
	return 0;
}

int main() {

	int board[50][50];
	int visit[50][50];
	queue<pair<int, int> > q;
	int count = 0;
	int row, col;

	while (1) {

		cin >> col >> row;

		if (row == 0 && col == 0)
			break;

		count = 0;
		init_visit(visit, row, col);
		while (!q.empty())
			q.pop();

		for (int y = 0; y < row; y++)
			for (int x = 0; x < col; x++)
				cin >> board[y][x];

		pair<int, int> current;

		for (int y = 0; y < row; y++) {
			for (int x = 0; x < col; x++) {
				if (in_boundary(x, y, row, col) && board[y][x]
						&& !visit[y][x]) {

					count += 1;
					q.push(make_pair(x, y));
					visit[y][x] = 1;

					while (!q.empty()) {

						current = q.front();
						q.pop();

						for (int i = 0; i < 8; i++) {
							if (in_boundary(current.first + diff_x[i],
									current.second + diff_y[i], row, col)
									&& !visit[current.second + diff_y[i]][current.first
											+ diff_x[i]]
									&& board[current.second + diff_y[i]][current.first
											+ diff_x[i]]) {
								visit[current.second + diff_y[i]][current.first
										+ diff_x[i]] = 1;
								q.push(
										make_pair(current.first + diff_x[i],
												current.second + diff_y[i]));
							}
						}
					}
				}
			}
		}
		cout << count << endl;

	}

	return 0;
}
