#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    int N;
    string str;
    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {

        cin >> N >> str;

        for (char i : str) {
            for (int j = 0; j < N; j++)
                cout << i;
        }

        cout << '\n';

    }
    return 0;
}