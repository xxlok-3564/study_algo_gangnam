//============================================================================
// Name        : 10808.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

	int arr[26];
	string a;

	for(int i = 0; i < 26; i++)
		arr[i] = 0;

	cin >> a;

	for(unsigned i = 0; i < a.size(); i++)
		arr[a[i] - 'a'] += 1;

	for(unsigned i = 0; i < 26; i++)
		cout << arr[i];

	return 0;
}
