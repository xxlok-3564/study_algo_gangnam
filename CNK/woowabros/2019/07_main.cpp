/*
#07
*/
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string cryptogram) {
  string answer = "";
  bool isChange = false;

  while(true) {
    answer = "";
    isChange = false;
    int n = cryptogram.size();    
    char prev_c = cryptogram[0];
    bool isOverlab = false;
    for(int i = 1; i <= n; i++) {
      if(i == n || prev_c != cryptogram[i]) {      
        if(!isOverlab) answer += prev_c;
        prev_c = cryptogram[i];
        isOverlab = false;
      } else {
        isOverlab = true;
        isChange = true;
      }
    }    
    cout << answer << "\n";
    if(!isChange) {
      break;
    }

    cryptogram = answer;
  }  

  return answer;
}

int main(int argc, char const *argv[])
{
  string word;
  getline(cin, word);
  solution(word);

  return 0;
}

