#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    while (1) {
        cin >> N;
        if (!N) break;

        while (N >= 10) {

            int ans = 0;

            while (N) {

                ans += (N % 10);
                N /= 10;

            }
            N = ans;
        }
        cout << N << "\n";
    }

    return 0;
}