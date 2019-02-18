/*
오픈채팅방
https://programmers.co.kr/learn/courses/30/lessons/42888
*/
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {
  
  vector<string> answer;// 정답 vector  
  map<string, string> user;// 사용자Id >> 사용자Name  
  vector<vector<string>> tokened_rec; // 토큰화된 사용자 기록  
  for (int i = 0; i < record.size(); i++) {
    stringstream ss(record[i]);
    vector<string> tokens;
    string str;
    
    while (ss >> str) {
      tokens.push_back(str);
    }

    if ("Enter" == tokens[0]) {
      cout << "Enter";
      // user[tokens[1]] = tokens[2];
      // tokened_rec.push_back(tokens);
    } else if ("Leave" == tokens[0]) {
      cout << "Leave";
      tokened_rec.push_back(tokens);
    } else {
      cout << "Change";
      // user[tokens[1]] = tokens[2];
    }
  }

  for (int i = 0; i < tokened_rec.size(); i++) {
    string str;
    if ("Enter" == tokened_rec[i][0]) {
      str = user[tokened_rec[i][1]] + " Enter.";
    } else {
      str = user[tokened_rec[i][1]] + " Leave.";
    }
    answer.push_back(str);
  }

  return answer;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  cin.ignore();

  vector<string> record(n);
  for (int i = 0; i < n; i++) {
    string str;
    getline(cin, str);
    record.push_back(str);
  }

  vector<string> answer = solution(record);
  for (int i = 0; i < n; i++) {
    cout << answer[i] << "\n";
  }

  return 0;
}
