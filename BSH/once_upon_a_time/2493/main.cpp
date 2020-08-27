#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int num_tower;

    cin >> num_tower;
    vector<int> arr(num_tower);
    stack<int> stk;

    for (int i = 0; i < num_tower; i++) {

        cin >> arr[i];

        while(true){
            if(stk.empty())
                break;
            if(arr[stk.top()] > arr[i])
                break;

            stk.pop();
        }

        if (stk.empty()) {
            cout << "0" << " ";
        } else {
            cout << stk.top() + 1 << " ";
        }

        stk.push(i);

    }

    return 0;
}