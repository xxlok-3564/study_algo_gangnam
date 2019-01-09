//============================================================================
// Name        : 11655.cpp
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
	getline(cin, a);

	for (unsigned i = 0; i < a.size(); i++) {
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] = ((a[i] - 'a' + 13) % 26) + 'a';
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] = ((a[i] - 'A' + 13) % 26) + 'A';
	}

	cout << a;

	return 0;
}
