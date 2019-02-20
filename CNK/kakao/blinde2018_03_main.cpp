/*
후보키
https://programmers.co.kr/learn/courses/30/lessons/42890
*/
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;

int ans;
int check[9];
int column_cnt;
vector<vector<int>> candidated;

void solve(int num, int idx, int cnt, vector<vector<string>> relation) {
  if (num > column_cnt) {
    return;
  }
  
  /* cnt개수 만큼 후보키가 만들어졌다면... */
  if (idx == cnt) {    
    /* 후보키의 조건이 되지 않는다면, return */
    /* 후보키의 조건은 이전에 후보키의 집합을 포함 하면 안된다.*/
    for (int i = 0; i < candidated.size(); i++) {
      int tmp_size = candidated[i].size();
      if (tmp_size < idx) {
        for (int j = 0; j < candidated[i].size(); j++) {
          for (int d = 0; d < idx; d++) {
            if (candidated[i][j] == check[d]) {
              tmp_size--;
            }
          }
        }

        if (tmp_size == 0) {
          return;
        }
      }
    }

    /* 유일한키가 될수 있는지 검사한다. */
    map<string, int> m;
    string key;
    for (int i = 0; i < relation.size(); i++) {
      key = "";
      for (int j = 0; j < idx; j++) {
        key += "_" + relation[i][check[j]];
      }
      if (m.find(key) == m.end()) {
        m[key] = 0;
      } else {
        /* 유일한 키가 되지 않는다면, return */
        return;
      }
    }
    
    /* 후보키 벡터 candidate에 추가한다. */
    vector<int> tmp_v(idx);
    for (int i = 0; i < idx; i++) {
      tmp_v[i] = check[i];
    }
    candidated.push_back(tmp_v);
    ans = cnt;

    return;
  }

  /* num을 후보키로 선택한다. */
  check[idx] = num;
  solve(num + 1, idx + 1, cnt, relation);

  /* num을 후보키로 선택하지 않는다. */
  check[idx] = 0;
  solve(num + 1, idx, cnt, relation);

  return;
}

int solution(vector<vector<string>> relation) {
  int answer = 0;
  column_cnt = relation[0].size();

  /**
   * 후보키를 1 ~ column_cnt개수만큼 조합을 만들어본다.
  */
  for (int i = 0; i < column_cnt; i++) {
    solve(0, 0, i + 1, relation);
  }

  /* 후보키가 저장된 candidated의 크기를 반환한다. */
  answer = candidated.size();
  return answer;
}

int main(int argc, char const *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<string>> relation(m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char word[50];
      string str;
      scanf("%s", word);
      str = word;
      relation[i].push_back(str);
    }
  }

  solution(relation);
  printf("ans :: %d\n", ans);
  for (int i = 0; i < candidated.size(); i++) {
    for (int j = 0; j < candidated[i].size(); j++) {
      printf("%3d ", candidated[i][j]);
    }
    printf("\n");
  }

  return 0;
}
