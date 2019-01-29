//============================================================================
// Name        : 11651.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

struct comp {
	bool operator ()(pair<int, int> a, pair<int, int> b) {

		if (a.second > b.second)
			return true;
		else if (a.second == b.second)
			if (a.first > b.first)
				return true;

		return false;
	}
};

int main() {
	priority_queue<pair<int, int>, vector<pair<int, int> >, comp> q;

	int N;
	pair<int, int> temp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp.first >> temp.second;
		q.push(temp);
	}

	for (int i = 0; i < N; i++) {
		cout << q.top().first << " " << q.top().second << '\n';
		q.pop();
	}

	return 0;
}
