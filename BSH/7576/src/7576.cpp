//============================================================================
// Name        : 7576.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>

using namespace std;

int diff_x[4] = { 1, -1, 0, 0 };
int diff_y[4] = { 0, 0, 1, -1 };

struct status {
	int x;
	int y;
	int step;
};

bool in_range(int x, int y, int M, int N) {
	if (x >= 0 && x < M && y >= 0 && y < N)
		return true;
	else
		return false;
}

bool _0_exist(int M, int N, int board[][1000]) {
	int x = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[j][i] == 0)
				x = 1;
			break;
		}
	}

	return x;

}
int main() {
	int M, N;
	int board[1000][1000];

	queue<struct status> Q;

	cin >> M >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {		// M->x
			cin >> board[j][i];
			if (board[j][i] == 1)
				Q.push( { j, i, 0 });
		}

	struct status temp;

	if (Q.empty()) {
		if (_0_exist(M, N, board))
			cout << -1;
		else
			cout << 0;
	} else {

		while (1) {
			temp = Q.front();
			Q.pop();

			for (int i = 0; i < 4; i++)
				if (in_range(temp.x + diff_x[i], temp.y + diff_y[i], M, N)
						&& board[temp.x + diff_x[i]][temp.y + diff_y[i]] == 0) {
					board[temp.x + diff_x[i]][temp.y + diff_y[i]] = 1;
					Q.push(
							{ temp.x + diff_x[i], temp.y + diff_y[i], temp.step
									+ 1 });
				}

			if (Q.empty())
				break;
		}

		if (_0_exist(M, N, board))
			cout << -1;
		else
			cout << temp.step;

	}

	return 0;
}
