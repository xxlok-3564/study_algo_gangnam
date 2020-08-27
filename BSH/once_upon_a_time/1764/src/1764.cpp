//============================================================================
// Name        : 1764.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);

	unordered_set<string> A;
	vector<string> ans;
	int num_A, num_B;
	string temp;

	cin >> num_A >> num_B;

	for (int i = 0; i < num_A; i++) {
		cin >> temp;
		A.insert(temp);
	}

	for (int i = 0; i < num_B; i++) {
		cin >> temp;
		if (A.end() != A.find(temp))
			ans.push_back(temp);
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';

	for (unsigned i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';

	return 0;
}
