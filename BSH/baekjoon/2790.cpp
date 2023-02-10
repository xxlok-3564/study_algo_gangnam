#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;

    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<>());

    int ans = 1;

    int left_max = arr[0] + 1;
    for (int i = 1; i < N; i++) {
        if (arr[i] + N >= left_max) {
            ans += 1;
        }

        if (arr[i] + i + 1 > left_max)
            left_max = arr[i] + i + 1;

    }

    cout << ans;

    return 0;
}