//============================================================================
// Name        : swea_2058.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int ans = 0;
	int num;
	cin >> num;
	while (num) {
		ans += (num % 10);
		num /= 10;
	}
	cout << ans;
	return 0;
}
