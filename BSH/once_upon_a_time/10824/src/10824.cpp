//============================================================================
// Name        : 10824.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define ll long long
using namespace std;

int find_digit(ll num){
	int digit =0;

	while(num > 0){
		num /=10;
		digit+=1;
	}

	return digit;
}

ll concat(ll num, int digit){

	for(int i = 0; i < digit; i++)
		num *= 10;

	return num;
}

int main() {

	ll A, B, C, D;

	cin >> A >> B >> C >> D;

	cout << concat(A, find_digit(B)) + B + concat(C, find_digit(D)) + D;

	return 0;
}
