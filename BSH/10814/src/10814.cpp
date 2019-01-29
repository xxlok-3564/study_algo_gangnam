//============================================================================
// Name        : 10814.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct age_name {
	int age;
	string name;
	int order;
};

struct comp {
	bool operator ()(age_name a, age_name b) {

		if (a.age > b.age)
			return true;
		else if (a.age == b.age)
			if (a.order > b.order)
				return true;

		return false;
	}
};

int main() {

	priority_queue<age_name, vector<age_name>, comp> q;

	int N;
	age_name temp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp.age >> temp.name;
		temp.order = i;
		q.push(temp);
	}

	for (int i = 0; i < N; i++) {
		cout << q.top().age << " " << q.top().name << '\n';
		q.pop();
	}

	return 0;
}
