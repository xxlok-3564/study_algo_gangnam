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

struct coord {
	int x;
	int y;
	int island;
	int step;
};

int diff_x[4] = { -1, 1, 0, 0 };
int diff_y[4] = { 0, 0, -1, 1 };

int in_boundary(int x, int y, int N) {
	if (x >= 0 && x < N && y >= 0 && y < N)
		return 1;
	return 0;
}

void init_board(int visit[100][100], int N) {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			visit[y][x] = 0;
}

int main() {

	int N;
	int board[100][100];
	int island[100][100];

	cin >> N;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> board[y][x];

	init_board(island, N);

	int num_island = 0;
	queue<pair<int, int> > q;
	pair<int, int> current;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (!island[y][x] && board[y][x]) {
				q.push( { x, y });
				num_island++;
				island[y][x] = num_island;

				while (!q.empty()) {
					current = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						if (in_boundary(current.first + diff_x[i],
								current.second + diff_y[i], N)
								&& board[current.second + diff_y[i]][current.first
										+ diff_x[i]]
								&& !island[current.second + diff_y[i]][current.first
										+ diff_x[i]]) {

							island[current.second + diff_y[i]][current.first
									+ diff_x[i]] = num_island;
							q.push(
									{ current.first + diff_x[i], current.second
											+ diff_y[i] });

						}
					}
				}
			}

	vector<coord> start_list;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (island[y][x]) {
				for (int i = 0; i < 4; i++) {
					if (in_boundary(x + diff_x[i], y + diff_y[i], N)
							&& island[y + diff_y[i]][x + diff_x[i]] == 0)

						start_list.push_back( { x + diff_x[i], y + diff_y[i],
								island[y][x], 1 });

				}
			}
		}
	}

	int ans = 0x7fff;
	queue<coord> coor_q;
	coord pos;
	coord new_pos;
	for (unsigned idx = 0; idx < start_list.size(); idx++) {

		if (ans == 1)
			break;

		init_board(board, N);	//board가 visit 역할
		while (!coor_q.empty())
			coor_q.pop();

		coor_q.push(start_list[idx]);
		board[coor_q.front().y][coor_q.front().x] = 1;

		while (!coor_q.empty()) {
			pos = coor_q.front();
			coor_q.pop();

			for (int i = 0; i < 4; i++) {
				new_pos = {pos.x + diff_x[i], pos.y + diff_y[i], pos.island, pos.step + 1};

				if(in_boundary(new_pos.x, new_pos.y, N)
						&& !board[new_pos.y][new_pos.x]
						&& island[new_pos.y][new_pos.x] == 0) {
					coor_q.push(new_pos);
					board[new_pos.y][new_pos.x] = 1;
				}

				if(in_boundary(new_pos.x, new_pos.y, N)
						&& island[new_pos.y][new_pos.x] != 0
						&& island[new_pos.y][new_pos.x] != pos.island) {
					if(pos.step < ans)
					ans = pos.step;
				}
			}
		}
	}

	cout << ans;

	return 0;
}
