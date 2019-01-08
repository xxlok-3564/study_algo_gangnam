//============================================================================
// Name        : 16234.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct coor {
	int x;
	int y;
};

int diff_x[4] = { 1, -1, 0, 0 };
int diff_y[4] = { 0, 0, 1, -1 };

void init_visit(bool visit[50][50], int board_size) {
	for (int y = 0; y < board_size; y++)
		for (int x = 0; x < board_size; x++)
			visit[y][x] = false;
}

bool in_boundary(coor pos, int board_size) {
	if (pos.x >= 0 && pos.x < board_size && pos.y >= 0 && pos.y < board_size)
		return true;
	return false;
}

bool in_range(coor origin_pos, coor new_pos, int board[50][50], int min,
		int max) {

	int diff = abs(
			board[new_pos.y][new_pos.x] - board[origin_pos.y][origin_pos.x]);

	if (diff <= max && diff >= min)
		return true;
	return false;
}

bool can_go(coor origin_pos, coor new_pos, int board[50][50], int board_size,
		bool visit[50][50], int min, int max) {
	if (in_boundary(new_pos, board_size) && !visit[new_pos.y][new_pos.x]
			&& in_range(origin_pos, new_pos, board, min, max))
		return true;
	return false;
}

void init_BFS_Q(queue<coor>& Q) {
	while (!Q.empty())
		Q.pop();
}

int main() {

	int board_size, min, max;
	int board[50][50];
	bool visit[50][50];

	cin >> board_size >> min >> max;

	for (int y = 0; y < board_size; y++)
		for (int x = 0; x < board_size; x++)
			cin >> board[y][x];

	//전체 횟수 카운터 루프, 전체 합치는 루프
	int ans = 0;
	bool open_history = false;
	int sum = 0;
	queue<coor> BFS_Q;
	vector<coor> history_vec(board_size * board_size);
	coor non_visit_pos;
	coor origin_pos;
	coor new_pos;

	while (1) {

		init_visit(visit, board_size);
		open_history = false;

		for (int y = 0; y < board_size; y++)
			for (int x = 0; x < board_size; x++)
				if (!visit[y][x]) {
					init_BFS_Q(BFS_Q);
					history_vec.clear();
					sum = 0;

					non_visit_pos.x = x;
					non_visit_pos.y = y;
					BFS_Q.push(non_visit_pos);
					visit[non_visit_pos.y][non_visit_pos.x] = true;

					while (!BFS_Q.empty()) {
						origin_pos = BFS_Q.front();
						history_vec.push_back(origin_pos);
						sum += board[origin_pos.y][origin_pos.x];
						BFS_Q.pop();
						for (int i = 0; i < 4; i++) {
							new_pos = origin_pos;
							new_pos.x += diff_x[i];
							new_pos.y += diff_y[i];
							if (can_go(origin_pos, new_pos, board, board_size,
									visit, min, max)) {
								BFS_Q.push(new_pos);
								visit[new_pos.y][new_pos.x] = true;
								open_history = true;
							}
						}
					}

					int avg = sum / history_vec.size();

					for (unsigned i = 0; i < history_vec.size(); i++)
						board[history_vec[i].y][history_vec[i].x] = avg;
				}

		if (open_history == false)
			break;
		else
			ans++;
	}

	cout << ans;

	return 0;
}
