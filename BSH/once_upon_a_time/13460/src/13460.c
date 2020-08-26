/*
 ============================================================================
 Name        : 13460.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define RED 0
#define BLUE 1

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

char map[10][10];
typedef struct {
	int row;
	int col;
} pos;

pos ball[2];

int ans = 12;

int dir_row[4] = { -1, 0, 1, 0 };
int dir_col[4] = { 0, 1, 0, -1 };

void cp_map(char origin[10][10], char current[10][10], int N, int M) {

	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			current[row][col] = origin[row][col];
}

void cp_ball(pos origin[2], pos current[2]) {

	current[0].row = origin[0].row;
	current[0].col = origin[0].col;
	current[1].row = origin[1].row;
	current[1].col = origin[1].col;

}

int check(int dir, pos ball[2]) {

	int check = -1;

	if (dir == UP)
		check = ball[RED].row < ball[BLUE].row ? RED : BLUE;
	else if (dir == DOWN)
		check = ball[RED].row >= ball[BLUE].row ? RED : BLUE;
	else if (dir == RIGHT)
		check = ball[RED].col >= ball[BLUE].col ? RED : BLUE;
	else
		check = ball[RED].col < ball[BLUE].col ? RED : BLUE;

	return check;
}

int move(int dir, pos* ball, pos other_ball, char map[10][10], int color) {

	int status = 0;

	while (1) {

		if (map[ball->row + dir_row[dir]][ball->col + dir_col[dir]] == 'O') {
			if (color == RED)
				status += 1;
			if (color == BLUE)
				status += 2;
			ball->row = -1;
			ball->col = -1;
			break;
		}

		if (map[ball->row + dir_row[dir]][ball->col + dir_col[dir]] == '#')
			break;

		if (((ball->row + dir_row[dir]) == other_ball.row)
				&& ((ball->col + dir_col[dir]) == other_ball.col))
			break;

		ball->row += dir_row[dir];
		ball->col += dir_col[dir];

	}

	return status;
}

int roll(int dir, char map[10][10], pos ball[2]) {

	int first = check(dir, ball);
	int status = 0;

	if (first == RED) {
		status += move(dir, &ball[RED], ball[BLUE], map, RED);
		status += move(dir, &ball[BLUE], ball[RED], map, BLUE);
	} else {
		status += move(dir, &ball[BLUE], ball[RED], map, BLUE);
		status += move(dir, &ball[RED], ball[BLUE], map, RED);
	}

	return status;
}

void complete(int depth, char origin_map[10][10], pos origin_ball[2], int N,
		int M) {

	if (depth == 11)
		return;

	int status = 0;
	char current_map[10][10];
	pos current_ball[2];

	for (int dir = 0; dir < 4; dir++) {
		cp_ball(origin_ball, current_ball);
		cp_map(origin_map, current_map, N, M);
		status = roll(dir, current_map, current_ball);

		if (status == 1) {
			if (depth < ans)
				ans = depth;
		}

		if (status != 0)
			continue;

		complete(depth + 1, current_map, current_ball, N, M);
	}

}

int main() {

	int N, M;

	scanf("%d %d", &N, &M);

	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++) {
			scanf(" %c", &map[row][col]);
			if (map[row][col] == 'B') {
				ball[BLUE].row = row;
				ball[BLUE].col = col;
			}
			if (map[row][col] == 'R') {
				ball[RED].row = row;
				ball[RED].col = col;
			}
		}

	complete(1, map, ball, N, M);

	if (ans == 12)
		ans = -1;

	printf("%d", ans);

	return 0;

}
