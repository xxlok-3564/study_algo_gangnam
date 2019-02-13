//============================================================================
// Name        : 1991.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

map<char, pair<char, char> > tree;

void pre(char node) {
	if (node == '.')
		return;

	cout << node;

	pre(tree[node].first);

	pre(tree[node].second);

}

void in(char node) {
	if (node == '.')
		return;

	in(tree[node].first);

	cout << node;

	in(tree[node].second);

}

void post(char node) {
	if (node == '.')
		return;

	post(tree[node].first);

	post(tree[node].second);

	cout << node;
}

int main() {

	int N;
	char A, B, C;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> A >> B >> C;

		tree.insert( { A, { B, C } });

	}

	tree.insert( { '.', { '.', '.' } });

	pre('A');
	cout << endl;
	in('A');
	cout << endl;
	post('A');

	return 0;
}
