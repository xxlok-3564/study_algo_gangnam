//============================================================================
// Name        : 1074.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

using namespace std;

int rec(int board_x, int board_y, int r, int c, int N) {

	int len_board = (int) pow(2, N);
	int quadrant;

	int center_x = board_x + len_board / 2;
	int center_y = board_y + len_board / 2;

	int new_x;
	int new_y;

	if (board_x <= c && c < center_x) {
		if (board_y <= r && r < center_y) {
			quadrant = 0;
			new_x = board_x;
			new_y = board_y;
		} else {
			quadrant = 2;
			new_x = board_x;
			new_y = center_y;
		}
	} else {
		if (board_y <= r && r < center_y) {
			quadrant = 1;
			new_x = center_x;
			new_y = board_y;
		} else {
			quadrant = 3;
			new_x = center_x;
			new_y = center_y;
		}
	}

	if (N == 1)
		return quadrant;

	return rec(new_x, new_y, r, c, N - 1) + quadrant * len_board / 4 * len_board;

}

int main() {
	int N;
	int r, c;

	cin >> N >> r >> c;

	cout << rec(0, 0, r, c, N);

	return 0;
}
