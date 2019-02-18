/*
실패율
https://programmers.co.kr/learn/courses/30/lessons/42889
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stage {
  int stage_no;
  double player_num;
  double not_clear_num;
  double fail_rate;
};

bool cmp(const Stage &a, const Stage &b) {
  if (a.fail_rate > b.fail_rate) {
    return true;
  } else if (a.fail_rate == b.fail_rate) {
    if (a.stage_no < b.stage_no) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

vector<int> solution(int N, vector<int> stages) {
  vector<int> answer;
  vector<Stage> games(N);  

  for (int i = 0; i < N; i++) {
    games[i].stage_no = i + 1;
    games[i].player_num = 0.0;
    games[i].not_clear_num = 0.0;
    games[i].fail_rate = 0.0;
  }

  for (int i = 0; i < stages.size(); i++) {
    int challenging = stages[i];
    if(challenging <= N) {
      games[challenging - 1].not_clear_num += 1;
    }
    
    for (int j = 0; (j < N) && (j < challenging); j++) {
      games[j].player_num += 1;
    }
  }
  
  for (int i = 0; i < N; i++) {
    if(games[i].player_num != 0) {
      games[i].fail_rate = games[i].not_clear_num / games[i].player_num;
    } else {
      games[i].fail_rate = 0;
    }    
  }

  sort(games.begin(), games.end(), cmp);

  for (int i = 0; i < N; i++) {
    answer.push_back(games[i].stage_no);
  }

  return answer;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> stages;
  for (int i = 0; i < 8; i++) {
    int num;
    cin >> num;
    stages.push_back(num);
  }

  vector<int> ans = solution(n, stages);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
