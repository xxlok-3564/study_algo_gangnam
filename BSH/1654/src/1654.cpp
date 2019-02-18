//============================================================================
// Name        : 1654.cpp
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

long long ans = 0;
long long target;

void find(long long first, long long end, vector<long long> &arr) {
	if (first > end)
		return;

	long long mid = (first + end) / 2;
	long long result = 0;

	for (long long lan : arr)
		result += lan / mid;

	cout << "first : " << first << " mid : " << mid << " end : " << end
			<< " result : " << result << endl;

	if (result >= target) {

		find(mid + 1, end, arr);
		if (ans < mid)
			ans = mid;

	} else
		find(first, mid - 1, arr);

}

int main() {
	int K, N;

	cin >> K >> N;
	vector<long long> arr(K);

	for (int i = 0; i < K; i++)
		cin >> arr[i];
	target = N;

	sort(arr.begin(), arr.end(), greater<int>());

	find(1, arr[0], arr);

	cout << ans;

	return 0;
}
