//============================================================================
// Name        : 2110.cpp
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

int num_router;
int ans = 0;

void rec(int min_len, int max_len, vector<int> &arr) {

	if (min_len > max_len)
		return;

	ll half_len = ((ll) min_len + (ll) max_len) / 2;

	int install_router = 0;
	int before = arr[0];
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] - before >= half_len) {
			install_router += 1;
			before = arr[i];
		}
	}

	install_router += 1;

	/*cout << "min : " << min_len << " half_len : " << half_len << " max : "
	 << max_len << " install : " << install_router << endl;*/

	if (install_router >= num_router) {

		rec(half_len + 1, max_len, arr);

		if (half_len > ans)
			ans = half_len;

	} else {
		rec(min_len, half_len - 1, arr);
	}

}

int main() {
	int num_house;

	cin >> num_house >> num_router;

	vector<int> arr(num_house);

	for (int i = 0; i < num_house; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int min_len = 1;
	int max_len = arr[num_house - 1];

	rec(min_len, max_len, arr);

	cout << ans;

	return 0;
}
