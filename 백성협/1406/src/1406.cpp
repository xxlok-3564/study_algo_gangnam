//============================================================================
// Name        : 1406.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	string str;
	stack<char> l_q;
	stack<char> r_q;
	int num_command;

	cin >> str;

	for(unsigned i = 0; i < str.size(); i++)
		l_q.push(str[i]);

	cin >> num_command;
	char command;
	for(int iter = 0; iter < num_command; iter++){
		cin >> command;
		if(command == 'L'){
			if(!l_q.empty()){
				r_q.push(l_q.top());
				l_q.pop();
			}
		}else if(command == 'D'){
			if(!r_q.empty()){
				l_q.push(r_q.top());
				r_q.pop();
			}
		}else if(command == 'B'){
			if(!l_q.empty())
				l_q.pop();
		}else if(command == 'P'){
			cin >> command;
			l_q.push(command);
		}

	}

	while(!l_q.empty()){
		r_q.push(l_q.top());
		l_q.pop();
	}

	while(!r_q.empty()){
		cout << r_q.top();
		r_q.pop();
	}

	return 0;
}
