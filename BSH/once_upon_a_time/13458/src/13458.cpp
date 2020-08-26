//============================================================================
// Name        : 13458.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	int N; // 시험장 갯수
	vector<int> room;
	int master, sub;

	ll num_people = 0;

	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		room.push_back(temp);
	}
	cin >> master >> sub;

	for (vector<int>::iterator start = room.begin(); start != room.end();
			start++) {

		temp = *start;

		temp -= master;
		num_people++;

		if (temp > 0) {
			num_people += (temp / sub);
			if (temp % sub != 0)
				num_people += 1;
		}

	}

	cout << num_people;

	return 0;
}
