//============================================================================
// Name        : 10872.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int result = 1;

	while(N > 0){
		result *= N;
		N--;
	}

	cout << result;

	return 0;
}
