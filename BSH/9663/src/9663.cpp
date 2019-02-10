//============================================================================
// Name        : 9663.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int board[15][15];

int ans = 0;

int in_range(int x, int y, int N) {

	if (x >= 0 && x < N && y >= 0 && y < N)
		return 1;
	return 0;

}

int can_put(int orig_x, int orig_y, int N) {

	int fail = 0;

	int up_y = orig_y - 1;
	int down_y = orig_y + 1;

	for (int new_x = orig_x - 1; new_x >= 0; new_x--) {

		if (board[new_x][orig_y])
			fail += 1;

		if (in_range(new_x, up_y, N)) {
			if (board[new_x][up_y])
				fail += 1;
			up_y--;
		}

		if (in_range(new_x, down_y, N)) {
			if (board[new_x][down_y])
				fail += 1;
			down_y++;
		}

		if (fail)
			break;
	}

	return !fail;
}

void df(int x, int N) {

	for (int y = 0; y < N; y++) {
		if (can_put(x, y, N)) {

			if (x == N - 1) {
				ans += 1;
				return;
			}

			board[x][y] = 1;
			df(x + 1, N);
			board[x][y] = 0;
		}
	}

}

int main() {

	// 가로 x 세로 y

	int N;
	cin >> N;

	df(0, N);

	cout << ans;

	return 0;
}
