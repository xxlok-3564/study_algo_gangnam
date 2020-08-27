//============================================================================
// Name        : 1967.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
bool visit[10001];

int search(int node, int parent, vector<pair<int, int> > link[10001]) {

	int max1 = 0, max2 = 0;
	int num_link = link[node].size();
	visit[node] = true;

	for (int i = 0; i < num_link; i++) {
		if (!visit[link[node][i].first]) {
			int temp = search(link[node][i].first, node, link) + link[node][i].second;

			if (temp > max1) {
				max2 = max1;
				max1 = temp;
			} else{
				if(temp > max2)
					max2 = temp;
			}

		}
	}

	if(max1 + max2 > ans)
		ans = max1 + max2;

	return max1;

}

int main() {
	int N;
	vector<pair<int, int> > link_list[10001];

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int A, B, C;

		cin >> A >> B >> C;

		link_list[A].push_back({B,C});
		link_list[B].push_back({A,C});
	}

	search(1, 0, link_list);

	cout << ans;

	return 0;
}
