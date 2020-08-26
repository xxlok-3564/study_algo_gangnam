//============================================================================
// Name        : 10820.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	int small, big, num, space;

	small = big = num = space = 0;

	while (getline(cin, str)) {
		for (unsigned i = 0; i < str.size(); i++) {
			char a = str[i];
			if (a >= 'a' && a <= 'z')
				small++;
			else if (a >= 'A' && a <= 'Z')
				big++;
			else if (a >= '0' && a <= '9')
				num++;
			else if (a == ' ')
				space++;
		}
		cout << small << " " << big << " " << num << " " << space << endl;
		small = big = num = space = 0;
	}

	return 0;
}
