/*
#01
*/
#include <string>
#include <vector>

using namespace std;

int arr[9] = {50000, 10000, 5000, 1000, 500, 100, 50, 10, 1};

vector<int> solution(int money) {
    vector<int> answer;
    
    for(int i = 0; i < 9; i++) {
        int cnt = money / arr[i];
        answer.push_back(cnt);
        money = money % arr[i];
        printf("%d, ", cnt);
    }
    
    return answer;
}

int main(int argc, char const *argv[])
{
  int money;
  scanf("%d", &money);
  solution(money);
  
  return 0;
}
