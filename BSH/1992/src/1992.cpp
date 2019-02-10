//============================================================================
// Name        : 1992.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

char board[65][65];

int can_merge(string a, string b, string c, string d) {

	int ans = 0;

	if (a.size() != 1 || b.size() != 1 || c.size() != 1 || d.size() != 1)
		return 0;

	if (a.compare(b) == 0 && c.compare(d) == 0 && b.compare(c) == 0)
		ans = 1;

	return ans;

}

string recursive(int l_x, int r_x, int l_y, int r_y) {

	string l_top, r_top, l_bot, r_bot;

	string temp;
	if (r_x - l_x == 1 && r_y - l_y == 1) {
		temp = board[l_y][l_x];
		return temp;
	} else {
		int center_x = (l_x + r_x) / 2;
		int center_y = (l_y + r_y) / 2;
		l_top = recursive(l_x, center_x, l_y, center_y);
		r_top = recursive(center_x, r_x, l_y, center_y);
		l_bot = recursive(l_x, center_x, center_y, r_y);
		r_bot = recursive(center_x, r_x, center_y, r_y);

	}

	if (can_merge(l_top, r_top, l_bot, r_bot)) {
		temp = l_top;
	} else {
		temp += "(";
		temp += (l_top + r_top + l_bot + r_bot);
		temp += ")";
	}

	return temp;

}

int main() {

	int N;

	cin >> N;

	char temp;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> temp;
			board[y][x] = temp;
		}
	}

	string a;
	a = recursive(0, N, 0, N);

	cout << a;

	return 0;
}
