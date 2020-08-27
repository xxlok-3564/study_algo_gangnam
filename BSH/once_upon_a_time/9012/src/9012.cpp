//============================================================================
// Name        : 9012.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

	int T;
	cin >> T;

	string a;

	for (int x = 0; x < T; x++) {

		cin >> a;
		stack<char> stk;
		char c;
		int fail = 0;
		for (unsigned i = 0; i < a.size(); i++) {
			c = a[i];

			if (c == '(')
				stk.push('(');
			else if (c == ')') {

				if (stk.empty()) {
					fail = 1;
					break;
				} else
					stk.pop();

			}

		}
		if (fail || !stk.empty())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

	}

	return 0;
}
