//============================================================================
// Name        : 11005.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

char changer[36];

void init_changer() {
	for (int i = 0; i < 10; i++)
		changer[i] = '0' + i;
	for (int i = 10; i < 36; i++)
		changer[i] = 'A' + i - 10;
}

int main() {

	int A, digit;
	int remain;
	string ans;

	init_changer();

	cin >> A >> digit;

	while (A) {
		remain = A % digit;
		A /= digit;
		ans += changer[remain];
	}

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];

	return 0;
}
