#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    for (int testcase = 1; testcase <= T; testcase++) {

        int N;
        int arr[100];
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        vector<bool> checker(N * 100 + 1, false);
        int ceiling = 0;
        checker[0] = true;

        for (int arr_idx = 0; arr_idx < N; arr_idx++) {

            for (int checker_idx = ceiling; checker_idx >= 0; checker_idx--) {
                if (checker[checker_idx]) {
                    checker[checker_idx + arr[arr_idx]] = true;
                }
            }

            ceiling += arr[arr_idx];

        }

        int ans = 0;
        for (bool a: checker)
            if (a) ans += 1;

        cout << "#" << testcase << " " << ans << '\n';

    }

    return 0;
}