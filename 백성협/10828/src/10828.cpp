//============================================================================
// Name        : 10828.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	int vec[10000];
	int idx = -1;

	cin >> N;

	string A;

	int num;
	for(int i = 0; i < N; i++){
		cin >> A;
		if(A == "push"){
			cin >> num;
			idx++;
			vec[idx] = num;
		}else if(A == "pop"){
			if(idx == -1)
				cout << "-1" << endl;
			else{
				cout << vec[idx] << endl;
				idx--;
			}
		}else if(A == "top"){
			if(idx == -1)
				cout << "-1" << endl;
			else
				cout << vec[idx] << endl;
		} else if(A == "empty"){
			if (idx == -1)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		} else if(A == "size"){
			cout << idx + 1 << endl;
		}


	}

/*push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

	return 0;
}
