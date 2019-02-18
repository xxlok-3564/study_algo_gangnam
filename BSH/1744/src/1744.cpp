//============================================================================
// Name        : 1744.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 양수 -> 절대값이 큰 것끼리 묶는다
// 음수 -> 절대값이 큰 것끼리 묶는다
// 0-> 음수 남는 것 중 큰 것이랑 묶어서 0을 만든다.

int main() {

	int N;
	int ans = 0;

	vector<int> plus;
	vector<int> minus;

	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp > 0)
			plus.push_back(temp);
		else
			minus.push_back(temp);
	}

	sort(plus.begin(), plus.end(), greater<int>());
	sort(minus.begin(), minus.end());

	int a, b;
	for (int i = 0; 2 * i + 1 < plus.size(); i++) {
		a = plus[2 * i];
		b = plus[2 * i + 1];
		if (a * b > a + b)
			ans += (a * b);
		else
			ans += (a + b);
	}
	if (plus.size() % 2 == 1)
		ans += plus[plus.size() - 1];

	for (int i = 0; 2 * i + 1 < minus.size(); i++) {
		a = minus[2 * i];
		b = minus[2 * i + 1];
		if (a * b > a + b)
			ans += (a * b);
		else
			ans += (a + b);
	}
	if (minus.size() % 2 == 1)
		ans += minus[minus.size() - 1];

	cout << ans;

	return 0;
}
