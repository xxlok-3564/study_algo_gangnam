//============================================================================
// Name        : 16235.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

int diff_x[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int diff_y[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

struct tree {
	int x;
	int y;
	int age;
};

bool in_boundary(int x, int y, int N) {
	return (x >= 1 && x <= N && y >= 1 && y <= N);
}

void init_board(int board[11][11], int N) {
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			board[y][x] = 0;
}

int main() {

	int N, M, K;	// board_size, tree_info, year
	tree init_tree[100];
	priority_queue<int, vector<int>, greater<int> > tree[11][11];
	queue<int> grow_tree[11][11];

	int add_energy[11][11];
	int energy_board[11][11];
	int dead_tree[11][11];

	cin >> N >> M >> K;

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> add_energy[y][x];

	for (int i = 0; i < M; i++) {
		cin >> init_tree[i].y >> init_tree[i].x >> init_tree[i].age;
		tree[init_tree[i].y][init_tree[i].x].push(init_tree[i].age);
	}

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			energy_board[y][x] = 5;

	init_board(dead_tree, N);

	for (int year = 0; year < K; year++) {

		//spring
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (!tree[y][x].empty()) {
					while (!tree[y][x].empty()
							&& tree[y][x].top() <= energy_board[y][x]) {
						energy_board[y][x] -= tree[y][x].top();
						grow_tree[y][x].push(tree[y][x].top() + 1);
						tree[y][x].pop();
					}
					while (!tree[y][x].empty()) {
						dead_tree[y][x] += (tree[y][x].top() / 2);
						tree[y][x].pop();
					}
				}
			}
		}

		//summer
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				energy_board[y][x] += dead_tree[y][x];
				dead_tree[y][x] = 0;
			}
		}

		//fall
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {

				while (!grow_tree[y][x].empty()) {
					tree[y][x].push(grow_tree[y][x].front());

					if (grow_tree[y][x].front() % 5 == 0) {
						for (int i = 0; i < 8; i++)
							if (in_boundary(y + diff_y[i], x + diff_x[i], N))
								tree[y + diff_y[i]][x + diff_x[i]].push(1);
					}
					grow_tree[y][x].pop();
				}

			}
		}

		//winter
		for (int y = 1; y <= N; y++)
			for (int x = 1; x <= N; x++)
				energy_board[y][x] += add_energy[y][x];

	}

	int ans = 0;

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			ans += tree[y][x].size();

	cout << ans;

	return 0;
}
