//============================================================================
// Name        : 15903.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main() {

	priority_queue<ll, deque<ll>, greater<ll> > q;
	int n, m;

	cin >> n >> m;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		q.push(temp);
	}

	for (int i = 0; i < m; i++) {
		ll a = q.top();
		q.pop();
		ll b = q.top();
		q.pop();

		q.push(a + b);
		q.push(a + b);
	}

	ll ans = 0;

	while (!q.empty()) {
		ans += q.top();
		q.pop();
	}

	cout << ans;

	return 0;
}
