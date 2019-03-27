#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string cryptogram) {
    string answer = "";
    stack<char> stk;

    for (int idx = 0; idx < cryptogram.size(); idx++){
        if (stk.empty())
            stk.push(cryptogram[idx]);
        else{

            if(cryptogram[idx] == stk.top())
                stk.pop();
            else
                stk.push(cryptogram[idx]);
        }
    }

    while (!stk.empty()) {
        answer += stk.top();
        stk.pop();
    }

    reverse(answer.begin(), answer.end());

    return answer;
}




int main() {



    return 0;
}