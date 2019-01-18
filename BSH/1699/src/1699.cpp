//============================================================================
// Name        : 1699.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int N;
	cin >> N;

	int square[100001];
	square[1] = 1;

	for(int i = 2; i <= N; i++){
		double root = sqrt(i);
		int lower = floor(root);
		int upper = ceil(root);

		if(lower == upper)
			square[i] = 1;
		else
			square[i] = square[ lower * lower ] + square[ i - lower * lower];
		cout << i << " " << square[i] << endl;
	}

	//cout << square[N];

	return 0;
}
