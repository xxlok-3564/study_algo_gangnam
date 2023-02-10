//============================================================================
// Name        : 1373.cpp
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
	cin >> in;

	if (in[in.size() - 1] == '0' && in.size() == 1)
		cout << "0";
	else {
		while (in.size() % 3)
			in = '0' + in;

		int sum = 0;
		int mul = 1;

		for (int i = in.size() - 1; i >= 0; i--) {

			int a = in[i] - '0';

			sum += (a * mul);
			mul *= 2;

			if (mul == 8) {
				ans += (sum + '0');
				mul = 1;
				sum = 0;
			}

		}

		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i];

	}

	return 0;
}
