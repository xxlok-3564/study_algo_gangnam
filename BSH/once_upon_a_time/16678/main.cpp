#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;

    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    long long ans = 0;
    int current = 1;
    for (int i = 0; i < N; i++) {

        if (arr[i] > current) {
            ans += arr[i] - current;
            current += 1;
        } else if (arr[i] == current) {
            current += 1;
        }

    }
    cout << ans;

    return 0;
}