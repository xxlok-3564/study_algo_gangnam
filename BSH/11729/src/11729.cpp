//============================================================================
// Name        : 11729.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
void df(int a, int b, int disk) {

	if (disk == 0)
		return;

	df(a, 6 - (a + b), disk - 1);

	cout << a << " " << b << '\n';

	df(6 - (a + b), b, disk - 1);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> ans;
	ans.push_back(1);

	for (int i = 1; i < N; i++)
		ans.push_back(2 * ans[i - 1] + 1);

	cout << ans[N - 1] << endl;

	df(1, 3, N);

	return 0;
}
