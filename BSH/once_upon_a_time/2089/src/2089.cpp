//============================================================================
// Name        : 2089.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void go(int n) {
	if (n == 0)
		return;
	if (n % 2 == 0) {
		go(-(n / 2));
		cout << "0";
	} else {
		if (n > 0)
			go(-(n / 2));
		else
			go(-(n - 1) / 2);
		cout << "1";
	}
}

int main() {

	int in;
	cin >> in;

	if (in == 0)
		cout << "0";
	else
		go(in);

	return 0;
}
