//============================================================================
// Name        : 11399.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	priority_queue<int, deque<int>, greater<int> > q;
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		q.push(temp);
	}

	long long ans = 0;
	long long sum = 0;
	while (!q.empty()) {
		sum = (sum + q.top());
		ans += sum;
		q.pop();
	}

	cout << ans;

	return 0;
}
