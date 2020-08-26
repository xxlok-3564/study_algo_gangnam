#include <iostream>

using namespace std;

int main() {
    int E, S, M;
    cin >> E >> S >> M;

    int start = 1;
    int e = 1, s = 1, m = 1;

    while (1) {

        if (e == E && s == S && m == M) {
            cout << start;
            break;
        }

        start++;

        e %= 15;
        s %= 28;
        m %= 19;

        e += 1;
        s += 1;
        m += 1;

    }


    return 0;
}