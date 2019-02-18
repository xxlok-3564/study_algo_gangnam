//============================================================================
// Name        : 1541.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	cin >> a;

	size_t pos;

	int base_num = stoi(a, &pos);
	a = a.substr(pos);

	int minus = 0;
	while (a.size() != 0) {

		if (a[0] == '-')
			minus = 1;

		a = a.substr(1);
		int temp = stoi(a, &pos);

		if (minus)
			base_num -= temp;
		else
			base_num += temp;

		a = a.substr(pos);

	}

	cout << base_num;

	return 0;
}
