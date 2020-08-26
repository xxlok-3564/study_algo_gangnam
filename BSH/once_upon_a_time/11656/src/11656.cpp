//============================================================================
// Name        : 11656.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {

	string a;
	priority_queue< string, vector<string>, greater<string> > pq;
	cin >> a;

	for(unsigned i =0; i < a.size(); i++)
		pq.push(a.substr(i, a.size()));

	for(unsigned i =0; i < a.size(); i++){
		cout << pq.top() << "\n";
		pq.pop();
	}



	return 0;
}
