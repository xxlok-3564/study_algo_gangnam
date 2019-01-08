//============================================================================
// Name        : 2042.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h+1));
	vector<long long> tree(tree_size);
	m += k;


	return 0;
}
