//============================================================================
// Name        : swea_2068.cpp
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

		cin >> ans;
		for (int j = 1; j < 10; j++) {
			cin >> temp;
			ans = max(temp, ans);
		}
		cout << "#" << i << " " << ans << endl;

	}
	return 0;
}
