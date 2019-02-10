//============================================================================
// Name        : 11723.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int set[21];
	int N;

	int number;
	char* line[10];
	string order;

	cin >> N;

	for (int i = 0; i < N; i++) {

		scanf("%s", line);
		printf("%s", line);
		/*
		if(line == "all" || line == "empty")
			order = line;
		else{


		}*/

		/*
		 if (order == "add")				// 명령어들 따로 묶어서 처리..?
		 set[number] = true;
		 else if (order == "remove")
		 set[number] = false;
		 else if (order == "check")
		 cout << set[number] << "\n";
		 else if (order == "toggle")
		 set[number] = !set[number];
		 else if (order == "all")
		 for (int i = 1; i <= 20; i++)
		 set[i] = true;
		 else if (order == "empty")
		 for (int i = 1; i <= 20; i++)
		 set[i] = false;
		 */
	}

	return 0;
}
