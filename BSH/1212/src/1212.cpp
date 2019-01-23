//============================================================================
// Name        : 1212.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string in;
	string ans;
	string changer[8] =
			{ "000", "100", "010", "110", "001", "101", "011", "111" };

	cin >> in;

	if (in.size() == 1 && in[0] == '0')
		cout << "0" << endl;
	else {

		for (int i = in.size() - 1; i >= 0; i--)
			ans += changer[in[i] - '0'];

		int flag = 1;
		for (int i = ans.size() - 1; i >= 0; i--) {

			if (flag == 1 && ans[i] == '0')
				continue;

			if (ans[i] == '1')
				flag = 0;

			cout << ans[i];

		}
	}

	return 0;
}
