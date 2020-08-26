//============================================================================
// Name        : 11723.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	int number;
	string order;
	bitset<20> ans;
	bitset<20> all;
	bitset<20> MT;

	for (int i = 0; i < 20; i++) {
		all.set(i);
		MT.reset(i);
	}

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> order;

		if (order == "add") {
			cin >> number;
			ans.set(number - 1);
		} else if (order == "remove") {
			cin >> number;
			ans.reset(number - 1);
		} else if (order == "check") {
			cin >> number;
			cout << ans[number - 1] << "\n";
		} else if (order == "toggle") {
			cin >> number;
			ans.flip(number - 1);
		} else if (order == "all")
			ans |= all;
		else if (order == "empty")
			ans &= MT;

	}

	return 0;
}
