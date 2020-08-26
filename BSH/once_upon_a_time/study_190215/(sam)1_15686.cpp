#include <stdio.h>

typedef struct position {
	int row;
	int col;
}pos;

int min_dis = 20000;

int chick_and_home[100][13];

int distance(pos home, pos chick) {

	int r = home.row - chick.row;
	if (r < 0)
		r = -r;
	int c = home.col - chick.col;
	if (c < 0)
		c = -c;

	return r + c;

}

void save_min(int M, pos* home_info, pos* chick_info, int home_num, int chick_num, int* selected_chick) {

	int val = 0;

	int min_home = 1000;

	for (int i = 0; i < home_num; i++) {
		min_home = 1000;
		for (int j = 0; j < chick_num; j++) {
			if (selected_chick[j] && (chick_and_home[i][j] < min_home)) 
				min_home = chick_and_home[i][j];
		}
		val += min_home;
	}

	if (val < min_dis)
		min_dis = val;

}

void find_min_val(int M, pos* home_info, pos* chick_info, int home_num, int chick_num, int* selected_chick, int start_idx, int selected_num) {


	for (int i = start_idx; i < chick_num; i++) {

		selected_chick[i] = 1;

		if (selected_num < M)
			find_min_val(M, home_info, chick_info, home_num, chick_num, selected_chick, i + 1, selected_num + 1);
		else if (selected_num == M)
			save_min(M, home_info, chick_info, home_num, chick_num, selected_chick);

		selected_chick[i] = 0;

	}


}

int main() {

	int map[50][50];

	pos home_info[100];
	int home_num = 0;
	pos chick_info[13];
	int chick_num = 0;

	int N, M;
	int selected_chick[100];

	for (int i = 0; i < 100; i++)
		selected_chick[i] = 0;


	scanf("%d", &N);
	scanf("%d", &M);

	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++) {
			scanf("%d", &map[row][col]);
			if (map[row][col] == 1) {
				home_info[home_num].row = row;
				home_info[home_num].col = col;
				home_num++;
			}
			else if (map[row][col] == 2) {
				chick_info[chick_num].row = row;
				chick_info[chick_num].col = col;
				chick_num++;
			}
		}

	for (int row = 0; row < home_num; row++)
		for (int col = 0; col < chick_num; col++)
			chick_and_home[row][col] = distance(home_info[row], chick_info[col]);

	find_min_val(M, home_info, chick_info, home_num, chick_num, selected_chick, 0, 1);


	printf("%d", min_dis);

	return 0;
}
