//============================================================================
// Name        : 16236.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

struct coor{
	int x;
	int y;
	int distance;
};

int diff_x[4] = {0, -1, 1, 0};
int diff_y[4] = {-1, 0, 0, 1};

bool in_boundary(coor pos, int board_size){
	if (pos.x >=0 && pos.x < board_size && pos.y >=0 && pos.y < board_size)
		return true;
	return false;
}

bool can_go(coor pos, int board_size, int whale_size, int food_size, bool visited[20][20]){
	if(in_boundary(pos, board_size) && (whale_size >= food_size) && !visited[pos.y][pos.x])
		return true;
	return false;
}

void init_visited(bool visited[20][20], int board_size){
	for(int y = 0; y < board_size; y++)
		for(int x = 0; x < board_size; x++)
			visited[y][x] = false;
}

void init_nearest(coor& nearest){
	nearest.distance = 300;
	nearest.x = 20;
	nearest.y = 20;
}

void update_nearest(coor& nearest, coor& obj){

	nearest = obj;

}

int main() {

	int board_size;
	int board[20][20];
	int c;

	int whale_size = 2;
	int ate_food = 0;

	coor init_whale;

	cin >> board_size;

	for(int y = 0; y < board_size; y++)
		for(int x = 0; x < board_size; x++){
			cin >> c;
			board[y][x] = c;

			if(c == 9){
				init_whale.x = x;
				init_whale.y = y;
				init_whale.distance = 0;
				board[y][x]= 0;
			}
		}

	coor nearest_food = init_whale;
	coor current_pos;
	coor candidate;
	coor way4;

	queue<coor> BFS_Q;
	bool no_more = true;
	bool visited[20][20];
	int ans = 0;
	int early_stop = 0;

	while(1){

		current_pos = nearest_food;
		current_pos.distance = 0;

		while(!BFS_Q.empty())
			BFS_Q.pop();
		init_visited(visited, board_size);
		init_nearest(nearest_food);

		BFS_Q.push(current_pos);
		visited[current_pos.y][current_pos.x] = true;
		no_more = true;
		early_stop = 0;

		while(!BFS_Q.empty()){

			candidate = BFS_Q.front();
			BFS_Q.pop();

			if(board[candidate.y][candidate.x] > 0
					&& board[candidate.y][candidate.x] < whale_size){

				no_more = false;

				if(candidate.distance < nearest_food.distance)
					update_nearest(nearest_food, candidate);
				else if(candidate.distance == nearest_food.distance){
					if(candidate.y < nearest_food.y)
						update_nearest(nearest_food, candidate);
					else if(candidate.y == nearest_food.y){
						if(candidate.x < nearest_food.x)
							update_nearest(nearest_food, candidate);
					}
				}
				else
					break;
			}

			for(int i = 0; i < 4; i++){
				way4 = candidate;
				way4.x += diff_x[i];
				way4.y += diff_y[i];
				way4.distance += 1;
				if(can_go(way4, board_size, whale_size, board[way4.y][way4.x], visited)){
					BFS_Q.push(way4);
					visited[way4.y][way4.x] = true;
				}
			}
		}

		if(no_more)
			break;
		else{
			board[nearest_food.y][nearest_food.x] = 0;
			ans += nearest_food.distance;
			ate_food += 1;

			if(ate_food == whale_size){
				ate_food = 0;
				whale_size += 1;
			}
		}
	}

	cout << ans;

	return 0;
}
