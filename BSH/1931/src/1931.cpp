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

bool comp(pair<int, int> &a, pair<int, int> &b) {

	if(a.first > b.first)
		return true;
	else{
		if(a.first == b.first){
			if(a.second > b.second)
				return true;
		}
	}

	return false;
}

int main() {

	int N;
	vector<pair<int, int> > arr;
	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr.push_back( { a, b });
	}

	sort(arr.begin(), arr.end(), comp);

	int end = arr[0].second;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if(arr[i].second <= end){
			end = arr[i].first;
			ans++;
		}
	}

	cout << ans;

	return 0;
}
