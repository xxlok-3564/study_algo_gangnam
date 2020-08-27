//============================================================================
// Name        : 2331.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Heinto World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int next_num(vector<int> &arr, int mul) {

	int num = *(arr.end() - 1);
	int ans = 0;

	while (num > 0) {

		int def = 1;
		int base = num % 10;

		for (int i = 0; i < mul; i++)
			def *= base;

		ans += def;

		num /= 10;
	}

	return ans;
}

pair<int, int> exist(vector<int> &arr, int num) {

	pair<int, int> exist;
	exist.first = 0;

	for (unsigned i = 0; i < arr.size() - 1; i++)
		if (num == arr[i]){
			exist.first = 1;
			exist.second = i;
		}

	return exist;
}
int main() {

	vector<int> arr;
	string start_num;
	int mul;

	pair<int, int> ans;

	cin >> start_num >> mul;

	arr.push_back(stoi(start_num));

	while (1) {

		int next = next_num(arr, mul);

		ans = exist(arr,next);
		if (ans.first) {
			cout << ans.second;
			break;
		} else
			arr.push_back(next);

	}

	return 0;
}
