//============================================================================
// Name        : 10610.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int main() {
	char num[100001];
	priority_queue<int> q;

	scanf("%s", num);

	int str_len = (int) strlen(num);
	bool zero_exist = false;	 // 초기화
	int remain = 0;
	int temp;
	for (int idx = 0; idx < str_len; idx++) {
		temp = num[idx] - '0';
		if (temp == 0)
			zero_exist = true;
		remain = (remain + temp) % 3;
		q.push(temp);
	}

	if (remain == 0 && zero_exist) {
		while (!q.empty()) {
			printf("%d", q.top());
			q.pop();
		}
	} else
		printf("-1");

	return 0;
}
