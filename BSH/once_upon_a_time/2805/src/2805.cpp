//============================================================================
// Name        : 2805.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int ans = 0;

void rec(int left, int right, int M, vector<int> &arr) {

	if (left > right)
		return;

	ll take_home = 0;
	ll mid = ((ll) left + (ll) right) / 2; // 절단기 높이

	for (int i = 0; i < arr.size() && arr[i] > mid; i++)
		take_home += (arr[i] - mid);

	//cout << "left : " << left << " right : " << right << " mid : " << mid
	//<< " take_home : " << take_home << endl;

	if (take_home >= M) {
		rec(mid + 1, right, M, arr);
		if (mid > ans)
			ans = mid;
	} else
		rec(left, mid - 1, M, arr);

}

int main() {

	int N, M;
	cin >> N >> M;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end(), greater<int>());

	rec(0, arr[0], M, arr);

	cout << ans;

	return 0;
}
