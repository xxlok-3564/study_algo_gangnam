//============================================================================
// Name        : 11650.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<pair<int, int>, vector<pair<int, int> >,
			greater<pair<int, int> > > q;

	int N;
	pair<int, int> temp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp.first >> temp.second;
		q.push(temp);
	}

	for(int i = 0; i < N; i++){
		cout << q.top().first << " " << q.top().second << '\n';
		q.pop();
	}

	return 0;
}
