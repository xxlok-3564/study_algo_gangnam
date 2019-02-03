//============================================================================
// Name        : 9466.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#define WHITE 0
#define RED 1
#define GRAY 2
#define BLACK 3
using namespace std;

int first_gray = 1;
int cycle_num;
int cycle = 0;
void DFS(vector<int> &arr, vector<int> &visit, int num) {
	int end;

	if (visit[num] == WHITE) {
		visit[num] = GRAY;
		DFS(arr, visit, arr[num]);
	}

	if (visit[num] == GRAY) {
		if (first_gray) {
			visit[num] = BLACK;
			first_gray = 0;
			cycle = 1;
			cycle_num = num;
			return;
		}

		if (cycle) {
			visit[num] = BLACK;
			return;
		} else {
			visit[num] = RED;
			return;
		}

	}

	if (visit[num] == BLACK || visit[num] == RED) {
		cycle = 0;
		return;
	}

}

int main() {

	int T;
	int N;
	vector<int> arr(100001);
	vector<int> visit(100001);

	int ans = 0;

	cin >> T;

	while (T--) {

		arr.clear();
		ans = 0;
		for (int i = 1; i <= N; i++)
			visit[i] = 0;

		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		for (int i = 1; i <= N; i++)
			if (visit[i] == WHITE) {
				first_gray = 1;
				cycle = 0;
				cycle_num = -1;
				DFS(arr, visit, i);
			}

		for (int i = 1; i <= N; i++)
			if (visit[i] == RED)
				ans += 1;

		cout << ans << endl;
	}

	return 0;
}
