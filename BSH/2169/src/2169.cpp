//============================================================================
// Name        : 2169.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int get_leftsum(int arr[1000][1000], int x, int y, int col) {
	int a = 0;

	for (int i = 0; i <= x; i++)
		a += arr[y][i];

	return a;
}

int get_rightsum(int arr[1000][1000], int x, int y, int col) {
	int a = 0;

	for (int i = x; i < col; i++)
		a += arr[y][i];

	return a;
}

int main() {

	int arr[1000][1000];
	int dp[1000][1000];

	int row, col;
	cin >> row >> col;

	for (int y = 0; y < row; y++)
		for (int x = 0; x < col; x++)
			cin >> arr[y][x];

	//init_dp
	dp[0][0] = arr[0][0];
	for (int i = 1; i < col; i++)
		dp[0][i] = dp[0][i - 1] + arr[0][i];

	int left_sum;
	int right_sum;
	int temp;
	int temp_max;

	for (int y = 1; y < row; y++) {
		for (int x = 0; x < col; x++) {
			temp_max = dp[y - 1][x] + arr[y][x];

			left_sum = get_leftsum(arr, x, y, col);
			right_sum = get_rightsum(arr, x, y, col);

			for (int left = 0; left < x; left++) {
				temp = dp[y - 1][left] + left_sum;
				left_sum -= arr[y][left];
				if (temp > temp_max)
					temp_max = temp;
			}

			for (int right = col - 1; right > x; right--) {
				temp = dp[y - 1][right] + right_sum;
				right_sum -= arr[y][right];
				if (temp > temp_max)
					temp_max = temp;
			}
			dp[y][x] = temp_max;
		}

	}

	cout << dp[row - 1][col - 1];

	return 0;
}
