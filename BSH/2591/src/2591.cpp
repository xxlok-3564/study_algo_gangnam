//============================================================================
// Name        : 2591.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#define ll long long
using namespace std;


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	string in;
	int arr[40];
	int dp[40][2];

	cin >> in;
	for(unsigned i = 0; i < in.size(); i++)
		arr[i] = in[i] - '0';

	dp[0][0] = 1;
	dp[0][1] = 0;





	return 0;
}
