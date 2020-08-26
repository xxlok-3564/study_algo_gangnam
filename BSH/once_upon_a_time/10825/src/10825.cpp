//============================================================================
// Name        : 10825.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct name_score {
	string name;
	int kor;
	int eng;
	int math;
};

struct comp {
	bool operator ()(name_score a, name_score b) {

		if (a.kor < b.kor)
			return true;
		else if (a.kor == b.kor) {
			if (a.eng > b.eng)
				return true;
			else if (a.eng == b.eng) {
				if (a.math < b.math)
					return true;
				else if (a.math == b.math)
					if (a.name > b.name)
						return true;
			}
		}

		return false;
	}
};

int main() {

	priority_queue<name_score, vector<name_score>, comp> q;

	int N;
	name_score temp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp.name >> temp.kor >> temp.eng >> temp.math;
		q.push(temp);
	}

	for (int i = 0; i < N; i++) {
		cout << q.top().name << '\n';
		q.pop();
	}

	return 0;
}
