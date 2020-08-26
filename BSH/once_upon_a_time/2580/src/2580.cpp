//============================================================================
// Name        : 2580.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int board[10][10];
int end_sig = 0;

void recursive(int idx, vector<pair<int, int> > &fill_list) {
	bool possible[10];
	fill_n(possible, 10, true);

	for (int x = 1; x <= 9; x++)
		possible[board[fill_list[idx].second][x]] = false;

	for (int y = 1; y <= 9; y++)
		possible[board[y][fill_list[idx].first]] = false;

	int range_x = (fill_list[idx].first - 1) / 3;
	int range_y = (fill_list[idx].second - 1) / 3;

	for (int y = range_y * 3 + 1; y <= range_y * 3 + 3; y++)
		for (int x = range_x * 3 + 1; x <= range_x * 3 + 3; x++)
			possible[board[y][x]] = false;

	for (int i = 1; i <= 9; i++) {
		if (possible[i]) {
			board[fill_list[idx].second][fill_list[idx].first] = i;
			if (idx == fill_list.size() - 1) {
				end_sig = 1;
				for (int y = 1; y <= 9; y++) {
					for (int x = 1; x <= 9; x++)
						cout << board[y][x] << " ";
					cout << endl;
				}
				return;
			}
			recursive(idx + 1, fill_list);
			if (end_sig)
				return;
			board[fill_list[idx].second][fill_list[idx].first] = 0;
		}
	}

}

int main() {

	int temp;
	vector<pair<int, int> > fill_list;

	for (int y = 1; y <= 9; y++) {
		for (int x = 1; x <= 9; x++) {
			cin >> temp;
			board[y][x] = temp;
			if (temp == 0)
				fill_list.push_back(make_pair(x, y));
		}
	}

	recursive(0, fill_list);

	return 0;
}
