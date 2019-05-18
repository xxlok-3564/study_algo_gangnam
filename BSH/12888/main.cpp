#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long ans = 1;

    for (int i = 1; i < N; i++) {

        if (i % 2 == 0) {
            ans = (ans - 1) * 2 + 1;
        } else {
            ans = ans * 2 + 1;
        }

    }

    cout << ans << '\n';

}