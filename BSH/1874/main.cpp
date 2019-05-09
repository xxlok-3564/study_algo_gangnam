#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    int N;
    vector<char> ans;
    stack<int> stk;
    bool fail = false;

    cin >> N;

    int temp;
    int current_num = 1;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        while (current_num <= temp) {
            stk.push(current_num);
            current_num += 1;
            ans.push_back('+');
        }

        if (stk.top() == temp) {
            stk.pop();
            ans.push_back('-');
        } else {
            fail = true;
        }

    }

    if (fail)
        cout << "NO";
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << '\n';
        }
    }

    return 0;
}