//============================================================================
// Name        : 2875.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int N, M, K;
	int ans = 0;
	cin >> N >> M >> K;

	while (1) {

		//셋이 빠지면 안되거나 남,녀가 충분하지 않으면...
		if (N + M - 3 < K || N < 2 || M < 1)
			break;

		N -= 2;
		M -= 1;
		ans++;
	}

	cout << ans;

	return 0;
}
