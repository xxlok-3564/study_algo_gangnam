#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {

        int N, K;

        cin >> N >> K;

        vector<double> arr(N);

        double temp;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            arr[i] = temp;
        }

        double ans = 0;

        sort(arr.begin(), arr.end());

        for (int i = N - K; i < N; i++)
            ans = (ans + arr[i]) / 2;

        cout.precision(11);

        cout << "#" << test << " " << ans << '\n';

    }

    return 0;
}