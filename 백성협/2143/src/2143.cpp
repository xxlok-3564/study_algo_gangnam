//============================================================================
// Name        : 2143.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

void find_insert(map<long long int, long long int> &m, long long int value){
	map<long long int, long long int>::iterator iter = m.find(value);
	if(iter != m.end())
		m[value] += 1;
	else
		m[value] = 1;
}

int main() {

	long long int ans = 0;

	int T, num_a, num_b;
	long long int A[1000];
	long long int B[1000];

	map<long long int, long long int> A_map;
	map<long long int, long long int> B_map;

	cin >> T;
	cin >> num_a;
	for(int i = 0; i < num_a; i++)
		cin >> A[i];

	cin >> num_b;
	for(int i = 0; i < num_b; i++)
		cin >> B[i];

	long long int sum = 0;
	for(int i = 0; i < num_a; i++){
		sum = A[i];
		find_insert(A_map, sum);
		for(int j = i + 1; j < num_a; j++){
			sum += A[j];
			find_insert(A_map, sum);
		}
	}

	for(int i = 0; i < num_b; i++){
		sum = B[i];
		find_insert(B_map, sum);
		for(int j = i + 1; j < num_b; j++){
			sum += B[j];
			find_insert(B_map, sum);
		}
	}

	map<long long int, long long int>::iterator a_iter;
	map<long long int, long long int>::iterator b_iter;

	for (a_iter = A_map.begin(); a_iter != A_map.end(); ++a_iter){
		b_iter = B_map.find(T - (a_iter->first));
		if(b_iter != B_map.end())
			ans += ((a_iter-> second) * (b_iter->second));
	}

	cout << ans;

	return 0;
}
