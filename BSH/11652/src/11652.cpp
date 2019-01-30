//============================================================================
// Name        : 11652.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main() {

	priority_queue<ll> q;

	int N;
	cin >> N;

	ll temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		q.push(temp);
	}

	long long current_num = q.top();
	int cnt = 1;
	int max_cnt = cnt;
	long long max_num = current_num;
	q.pop();

	while (!q.empty()) {
		if (current_num == q.top()) {
			cnt++;
		} else {
			if (cnt >= max_cnt) {
				max_cnt = cnt;
				max_num = current_num;
			}
			current_num = q.top();
			cnt = 1;
		}

		q.pop();
	}

	if (cnt >= max_cnt) {
		max_cnt = cnt;
		max_num = current_num;
	}
	cout << max_num;

	return 0;
}
