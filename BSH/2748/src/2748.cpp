//============================================================================
// Name        : 2748.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define ll long long
using namespace std;

int main() {

	ll arr[91];
	arr[0] = 0;
	arr[1] = 1;

	int a;

	cin >> a;

	for(int i = 2; i <= a; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[a];

	return 0;
}
