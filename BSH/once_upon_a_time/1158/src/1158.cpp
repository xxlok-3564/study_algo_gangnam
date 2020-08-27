//============================================================================
// Name        : 1158.cpp
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
	int M;
	queue<int> q;

	cin >> N >> M;

	for(int i = 0; i < N; i++)
		q.push(i + 1);

	cout << "<";

	while(!q.empty()){

		for(int i = 0; i < M - 1; i++){
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		if(q.size() > 1)
			cout << ", ";
		q.pop();

	}

	cout << ">";

	return 0;
}
