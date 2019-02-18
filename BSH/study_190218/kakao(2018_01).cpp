//============================================================================
// Name        : KAKAO_오픈채팅방.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#define ENTER 0
#define LEAVE 1

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<string, int> > sequence;
	unordered_map<string, string> id_nick;
	for (int i = 0; i < (int) record.size(); i++) {

		size_t pos1 = record[i].find(' ');
		size_t pos2 = record[i].find(' ', pos1 + 1);
		char command = record[i][0];
		string id = record[i].substr(pos1 + 1, pos2 - pos1 - 1);
		string nick = record[i].substr(pos2 + 1);

		switch (command) {

		case 'E':
			id_nick[id] = nick;
			sequence.push_back( { id, ENTER });
			break;
		case 'L':
			sequence.push_back( { id, LEAVE });
			break;
		case 'C':
			id_nick[id] = nick;
			break;

		}

	}

// 답지 처리

	for (int i = 0; i < sequence.size(); i++) {
		string temp = id_nick[sequence[i].first] + "님이 ";
		if (sequence[i].second == LEAVE)
			temp += "나갔습니다.";
		else
			temp += "들어왔습니다.";

		answer.push_back(temp);
	}

	return answer;
}

int main() {

	string a = "Enter uid1234 Muzi";

	size_t pos1 = a.find(' ');
	size_t pos2 = a.find(' ', pos1 + 1);
	char command = a[0];
	string id = a.substr(pos1 + 1, pos2 - pos1 - 1);
	string nick = a.substr(pos2 + 1);

	cout << id << endl;

	cout << nick;

	return 0;
}
