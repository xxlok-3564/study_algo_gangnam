#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    string str;
    stack<char> stk;

    cin >> str;

    int ans = 0;
    int base = 1;
    bool fail = false;

    for (int i = 0; i < str.size(); i++) {

        if (str[i] == '[') {
            stk.push(str[i]);
            base *= 3;
        }

        if (str[i] == '(') {
            stk.push(str[i]);
            base *= 2;
        }

        if (str[i] == ')') {

            if (stk.empty() || stk.top() == '[') {
                fail = true;
                break;
            } else if (str[i - 1] == '(') {
                ans += base;
            }

            base /= 2;
            stk.pop();

        }

        if (str[i] == ']') {

            if (stk.empty() || stk.top() == '(') {
                fail = true;
                break;
            } else if (str[i - 1] == '[') {
                ans += base;
            }

            base /= 3;
            stk.pop();

        }

    }


    if (fail || !stk.empty())
        cout << '0';
    else
        cout << ans;

    return 0;
}