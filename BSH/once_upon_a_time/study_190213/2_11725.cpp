//============================================================================
// Name        : 11725.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void search(int node, int node_parent, int parent[100001], int visit[100001],
		vector<int> link_list[100001]) {

	parent[node] = node_parent;
	visit[node] = 1;

	for (unsigned i = 0; i < link_list[node].size(); i++) {
		if (!visit[link_list[node][i]])
			search(link_list[node][i], node, parent, visit, link_list);
	}

}

int main() {

	int parent[100001];
	int visit[100001];
	vector<int> link_list[100001];

	int N;
	cin >> N;

	int A, B;
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B;
		link_list[A].push_back(B);
		link_list[B].push_back(A);
	}

	search(1, 0, parent, visit, link_list);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';

	return 0;
}
