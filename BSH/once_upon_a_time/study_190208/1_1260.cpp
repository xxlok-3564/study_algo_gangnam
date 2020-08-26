//============================================================================
// Name        : 1260.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void init_arr(int point_to_point_info[1001][1001], int visited[1001]) {
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			point_to_point_info[i][j] = 0;

	for (int i = 0; i < 1001; i++)
		visited[i] = 0;
}

int main() {
	int N, M, V;
	int point_to_point_info[1001][1001];
	int visited[1001];

	cin >> N >> M >> V;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		point_to_point_info[a][b] = 1;
		point_to_point_info[b][a] = 1;
	}

	queue<int> q;
	stack<int> stk;
	int temp;

	int can_go = 0;
	stk.push(V);
	visited[V] = 1;
	cout << V;

	while (!stk.empty()) {

		can_go = 0;
		for (int i = 1; i <= N; i++) {
			if (point_to_point_info[stk.top()][i] && !visited[i]) {
				stk.push(i);
				visited[i] = 1;
				can_go = 1;
				cout << " " << i;
				break;
			}
		}

		if (!can_go)
			stk.pop();

	}

	cout << endl;

	for (int i = 0; i < 1001; i++)
		visited[i] = 0;

	q.push(V);
	visited[V] = 1;

	while (!q.empty()) {

		cout << q.front() << " ";
		temp = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
			if (point_to_point_info[temp][i] && !visited[i]) {
				visited[i] = 1;
				q.push(i);
			}
	}

	return 0;
}
