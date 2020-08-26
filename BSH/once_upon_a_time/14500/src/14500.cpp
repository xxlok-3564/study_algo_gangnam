//============================================================================
// Name        : 14500.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct coor{
	int x;
	int y;
};


coor get_boundary(int row, int col, coor* position){
	coor ans = {col, row};

	int max_x = 0;
	int max_y = 0;

	for(int i = 0; i < 4; i++){
		if(position[i].x > max_x) max_x = position[i].x;
		if(position[i].y > max_y) max_y = position[i].y;
	}

	ans.x -= max_x;
	ans.y -= max_y;

	return ans;
}

coor blocks[76] ={

		{0,0}, {1,0}, {0,1}, {1,1},

		{0,0}, {0,1}, {0,2}, {0,3},
		{0,0}, {1,0}, {2,0}, {3,0},

		{0,0}, {0,1}, {0,2}, {1,2},
		{0,1}, {1,1}, {2,1}, {2,0},
		{0,0}, {1,0}, {1,1}, {1,2},
		{0,1}, {0,0}, {1,0}, {2,0},
		{0,2}, {1,2}, {1,1}, {1,0},
		{0,0}, {1,0}, {2,0}, {2,1},
		{1,0}, {0,0}, {0,1}, {0,2},
		{0,0}, {0,1}, {1,1}, {2,1},

		{0,0}, {0,1}, {1,1}, {1,2},
		{0,1}, {1,1}, {1,0}, {2,0},
		{1,0}, {1,1}, {0,1}, {0,2},
		{0,0}, {1,0}, {1,1}, {2,1},

		{1,0}, {0,1}, {1,1}, {2,1},
		{0,0}, {0,1}, {1,1}, {0,2},
		{0,0}, {1,0}, {1,1}, {2,0},
		{0,1}, {1,0}, {1,1}, {1,2}

};

int main() {

	/*for(int num_block = 0; num_block < 19; num_block++){

		int board[4][4] = {0,0,0,};

		board[blocks[4 * num_block + 0].y][blocks[4 * num_block + 0].x] = 1;
		board[blocks[4 * num_block + 1].y][blocks[4 * num_block + 1].x] = 1;
		board[blocks[4 * num_block + 2].y][blocks[4 * num_block + 2].x] = 1;
		board[blocks[4 * num_block + 3].y][blocks[4 * num_block + 3].x] = 1;

		for(int y=0; y < 4; y++){
			for(int x=0; x<4; x++){
				cout << board[y][x];
			}
			cout << endl;
		}

		cout << endl;
	}*/


	int row, col;
	int board[500][500];
	int ans = 0;
	cin >> row >> col;

	for(int y = 0; y < row; y++)
		for(int x = 0; x < col; x++)
			cin >> board[y][x];

	for(int num_block = 0; num_block < 19; num_block++){

		coor boundary = get_boundary(row, col, blocks + 4 * num_block);

		for(int y = 0; y < boundary.y; y++)
			for(int x = 0; x < boundary.x; x++){
				int sum = 0;
				sum += board[y + blocks[4 * num_block + 0].y][x + blocks[4 * num_block + 0].x];
				sum += board[y + blocks[4 * num_block + 1].y][x + blocks[4 * num_block + 1].x];
				sum += board[y + blocks[4 * num_block + 2].y][x + blocks[4 * num_block + 2].x];
				sum += board[y + blocks[4 * num_block + 3].y][x + blocks[4 * num_block + 3].x];
				if (sum > ans) ans = sum;
			}

	}

	cout << ans;


	return 0;
}
