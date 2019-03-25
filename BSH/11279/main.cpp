#include <iostream>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> p_q;


    int command;

    cin >> command;

    for (int i = 0; i < command; i++) {

        int N;
        cin >> N;

        if (N == 0) {

            if (p_q.empty())
                cout << '0' << '\n';
            else {
                cout << p_q.top() << '\n';
                p_q.pop();
            }


        } else
            p_q.push(N);


    }

    return 0;
}