//============================================================================
// Name        : 3052.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int ans[42];

int main() {
	int table[10];

	for (int i = 0; i < 10; i++) {
		cin >> table[i];
		ans[table[i] % 42] = 1;
	}

	int tt = 0;
	for (int i = 0; i < 42; i++)
		tt += ans[i];

	cout << tt;

	return 0;
}
