//============================================================================
// Name        : 1377.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct val_pos {
	int val;
	int pos;
};

struct comp {
	bool operator ()(const val_pos &a, const val_pos &b) {
		if (a.val > b.val)
			return false;
		else if(a.val == b.val)
			if(a.pos > b.pos)
				return false;

		return true;
	}
};

int main() {

	int n;
	val_pos arr[500000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].val);
		arr[i].pos = i;
	}

	/*for (int i = 0; i < n; i++)
		cout << "(" << arr[i].val << " " << arr[i].pos << ") ";*/

	sort(arr, arr + n, comp());
	/*printf("\n");
	for (int i = 0; i < n; i++)
		cout << "(" << arr[i].val << " " << arr[i].pos << ") ";*/

	int max = 0;
	for (int i = 0; i < n; i++)
		if (arr[i].pos - i > max)
			max = arr[i].pos - i;

	printf("%d", max + 1);

	return 0;
}
