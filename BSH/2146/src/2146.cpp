//============================================================================
// Name        : 2146.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int diff_x[4] = { -1, 1, 0, 0 };
int diff_y[4] = { 0, 0, -1, 1 };

struct point_info {
	int x;
	int y;
	int num_island;
	int depth;
};

int in_boundary(int x, int y, int N) {
	if (x >= 0 && x < N && y >= 0 && y < N)
		return 1;
	return 0;
}

void init_visit(int visit[100][100], int N) {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			visit[y][x] = 0;
}

int main() {
	int board[100][100];
	int diff_board[100][100];
	int N;
	int ans = 0;
	cin >> N;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> board[y][x];

	// 다른 섬으로 표시
	int num_island = 2;
	queue<pair<int, int> > q;
	pair<int, int> current;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (!diff_board[y][x] && board[y][x]) {
				q.push(make_pair(x, y));
				diff_board[y][x] = num_island;

				while (!q.empty()) {
					current = q.front();
					q.pop();
					for (int i = 0; i < 4; i++) {
						if (in_boundary(current.first + diff_x[i],
								current.second + diff_y[i], N)
								&& board[current.second + diff_y[i]][current.first
										+ diff_x[i]] == 1
								&& !diff_board[current.second + diff_y[i]][current.first
										+ diff_x[i]]) {
							diff_board[current.second + diff_y[i]][current.first
									+ diff_x[i]] = num_island;
							q.push(
									make_pair(current.first + diff_x[i],
											current.second + diff_y[i]));
						}
					}
				}

				num_island++;
			}
		}
	}
	// 여기까지 하면 diff보드에 섬 번호 저장 됨

	init_visit(board, N); // board를 visit 표시 용도로 사용

	vector<point_info> point_q;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (diff_board[y][x] == 0) {
				for (int i = 0; i < 4; i++) {
					if (in_boundary(x + diff_x[i], y + diff_y[i], N)
							&& diff_board[y + diff_y[i]][x + diff_x[i]])
						point_q.push_back(
								{ x, y,
										diff_board[y + diff_y[i]][x + diff_x[i]],
										1 });
				}
			}
		}
	}

	for(vector<point_info>::iterator start;;)

	return 0;
}
