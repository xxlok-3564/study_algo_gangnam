//============================================================================
// Name        : 9019.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void rec(int before_command, string origin, string &ans, string &command_list,
		int str_idx) {

	string temp_str;
	int temp_int;

	for (int i = 0; i < 4; i++) {

		temp_str = origin;

		if (i == 0) {
			command_list += 'D';


		} else if (i == 1) {
			command_list[str_idx] = 'S';

		} else if (i == 2 && before_command != 3) {
			command_list[str_idx] = 'L';

		} else if (i == 3 && before_command != 2) {
			command_list[str_idx] = 'R';

		}

		if (temp_str == ans)
			return;
		else
			rec(i, temp_str, ans, command_list, str_idx + 1);

	}

}

int main() {

	int T;
	cin >> T;

	for (int test = 0; test < T; test++) {

		string a, b;

		string ans;

		cin >> a >> b;

	}

	return 0;
}
