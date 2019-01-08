//============================================================================
// Name        : 10866.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*push_front X: 정수 X를 덱의 앞에 넣는다.
 push_back X: 정수 X를 덱의 뒤에 넣는다.
 pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 size: 덱에 들어있는 정수의 개수를 출력한다.
 empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
 front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다. */
int main() {

	stack<int> l;
	stack<int> r;

	int N;
	int X;
	string str;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push_front") {
			cin >> X;
			while (!l.empty()) {
				r.push(l.top());
				l.pop();
			}
			r.push(X);
			while (!r.empty()) {
				l.push(r.top());
				r.pop();
			}
		} else if (str == "push_back") {
			cin >> X;
			l.push(X);
		} else if (str == "pop_front") {
			if (l.empty())
				cout << "-1" << endl;
			else {
				while (!l.empty()) {
					r.push(l.top());
					l.pop();
				}
				cout << r.top() << endl;
				r.pop();
				while (!r.empty()) {
					l.push(r.top());
					r.pop();
				}
			}
		} else if (str == "pop_back") {
			if (l.empty())
				cout << "-1" << endl;
			else {
				cout << l.top() << endl;
				l.pop();
			}
		} else if (str == "size") {
			cout << l.size() << endl;
		} else if (str == "empty") {
			if (l.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		} else if (str == "front") {
			if (l.empty())
				cout << "-1" << endl;
			else {
				while (!l.empty()) {
					r.push(l.top());
					l.pop();
				}
				cout << r.top() << endl;
				while (!r.empty()) {
					l.push(r.top());
					r.pop();
				}
			}
		} else if (str == "back") {
			if (l.empty())
				cout << "-1" << endl;
			else
				cout << l.top() << endl;
		}
	}

	return 0;
}
