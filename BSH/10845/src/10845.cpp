//============================================================================
// Name        : 10845.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



int main() {

	int N;
	string str;
	cin >> N;
	int num;

	int arr[10000];
	int front=0; int rear=0; int empty = 1;

	for(int i = 0; i < N; i++){

		cin >> str;

		if(str == "push"){
			cin >> num;
			arr[rear] = num;
			rear += 1;
			rear %= 10000;
			if (empty == 1)
				empty = 0;
		}else if(str == "pop"){
			if(empty == 1)
				cout << "-1" << endl;
			else{
				cout << arr[front] << endl;
				front +=1;
				front %= 10000;
				if(front == rear)
					empty = 1;
			}
		}else if(str == "size"){
			if (rear >= front){
				cout << rear - front << endl;
			} else{
				cout << 10000 - rear + front << endl;
			}
		}else if(str == "empty"){
			if(empty == 1)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}else if(str == "front"){
			if(empty)
				cout << "-1" << endl;
			else
				cout << arr[front] << endl;
		}else if(str == "back"){
			if(empty)
				cout << "-1" << endl;
			else
				cout << arr[rear - 1] << endl;
		}
		cout << "front: " << front << " rear: " << rear << endl;
	}

	return 0;
}
