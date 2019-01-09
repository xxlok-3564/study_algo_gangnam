//============================================================================
// Name        : 10809.cpp
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

	cin >> a;

	for (int i = 0; i < 26; i++)
		arr[i] = -1;

	for (unsigned i = 0; i < a.size(); i++)
		if (arr[a[i] - 'a'] == -1)
			arr[a[i] - 'a'] = i;

	for (unsigned i = 0; i < 26; i++)
		cout << arr[i] << " ";

	return 0;
}
