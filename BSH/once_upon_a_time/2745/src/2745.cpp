//============================================================================
// Name        : 2745.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

	string ans;
	char a;
	int digit;
	int sum = 0;
	cin >> ans >> digit;

	int where = 1;
	for(int loc = ans.size() - 1; loc >= 0; loc--){

		a = ans[loc];

		if('0' <= a && a <= '9')
			sum += ((a - '0') * where);
		else if('A' <= a && a <= 'Z')
			sum += ((a - 'A' + 10) * where);

		where *= digit;
	}

	cout << sum;

	return 0;
}
