#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    int T;
    cin >> T;

    for (int test = 0; test < T; test++) {

        int ans = 0;
        string str;
        stack<char> stk;

        cin >> str;
        char present;
        char before;

        for (unsigned iter = 0; iter < str.size(); iter++) {
            present = str[iter];

            if (present == '(')
                stk.push('(');
            else if (present == ')') {
                if (before == '(') {
                    stk.pop();
                    ans += stk.size();
                } else if (before == ')') {
                    stk.pop();
                    ans += 1;
                }
            }

            before = present;

        }

        cout << "#" << test + 1 << " " << ans << '\n';

    }

    return 0;
}