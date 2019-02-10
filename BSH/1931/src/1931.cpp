//============================================================================
// Name        : 1931.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int> > arr(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr.begin(), arr.end(), greater<pair<int, int> >());

	int ans = 0;
	int end_time = 0x8fff;

	vector<pair<int, int> >::iterator iter = arr.begin();

	for (unsigned i = 0; i < arr.size(); i++) {
		if (arr[i].second <= end_time) {
			ans++;
			end_time = arr[i].first;
		}
	}

	cout << ans;

	return 0;
}
