//============================================================================
// Name        : 1780.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct pixel {
	int minus = 0;
	int zero = 0;
	int plus = 0;
	int mixed = 0;
};

pixel board[2187][2187];

bool can_merge(pixel collection[3][3]) {
	int cant = 0;

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cant += collection[y][x].mixed;
		}
	}

	int a = 0, b = 0, c = 0;

	if (!cant) {
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				a += collection[y][x].minus;
				b += collection[y][x].zero;
				c += collection[y][x].plus;
			}
		}
	}

	if (!(a == 9 || b == 9 || c == 9))
		cant += 1;

	return !cant;
}

pixel recursive(int lx, int rx, int ly, int ry) {

	pixel collection[3][3];
	pixel total;

	if (rx - lx == 1 && ry - ly == 1)
		return board[ly][lx];

	int sector_len_x = (rx - lx) / 3;
	int sector_len_y = (ry - ly) / 3;

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			collection[y][x] = recursive(lx + x * sector_len_x,
					lx + (x + 1) * sector_len_x, ly + y * sector_len_y,
					ly + (y + 1) * sector_len_y);
		}
	}

	if (can_merge(collection)) {
		total = collection[0][0];
	} else {
		total.mixed = 1;
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				total.minus += collection[y][x].minus;
				total.zero += collection[y][x].zero;
				total.plus += collection[y][x].plus;
			}
		}
	}

	return total;

}

int main() {
	int N;
	cin >> N;

	int temp;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> temp;
			if (temp == -1)
				board[y][x].minus = 1;
			else if (temp == 0)
				board[y][x].zero = 1;
			else if (temp == 1)
				board[y][x].plus = 1;
		}
	}

	pixel ans = recursive(0, N, 0, N);

	cout << ans.minus << '\n' << ans.zero << '\n' << ans.plus;

	return 0;
}
