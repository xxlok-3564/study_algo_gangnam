//============================================================================
// Name        : 10799.cpp
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

	string pipe_lazer;
	int ans = 0;
	cin >> pipe_lazer;

	stack<char> stk;
	char present;
	char before;

	for (unsigned iter = 0; iter < pipe_lazer.size(); iter++) {
		present = pipe_lazer[iter];

		if (present == '(')
			stk.push('(');
		else if (present == ')') {
			if (before == '(') {
				stk.pop();
				ans += stk.size();
			} else if(before == ')'){
				stk.pop();
				ans += 1;
			}
		}

		before = present;

	}

	cout << ans;

	return 0;
}
