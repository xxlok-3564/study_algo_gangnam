//============================================================================
// Name        : 2751.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

void swap(int &a, int & b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int N;
	priority_queue< int, vector<int>, greater<int> > q;
	cin >> N;

	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		q.push(t);
	}

	for (int i = 0; i < N; i++) {
		cout << q.top() << '\n';
		q.pop();
	}
	return 0;
}
