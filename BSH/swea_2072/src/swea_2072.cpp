//============================================================================
// Name        : swea_2072.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int ans = 0;
		int temp;
		for (int j = 0; j < 10; j++) {
			cin >> temp;
			if (temp % 2 == 1)
				ans += temp;
		}
		cout << "#" << i << " " << ans << endl;

	}
	return 0;
}
