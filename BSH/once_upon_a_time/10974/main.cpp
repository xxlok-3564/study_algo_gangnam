#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<int> arr;

    cin >> N;

    arr.resize(N);

    for (int i = 0; i < N; i++)
        arr[i] = i + 1;

    do {

        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";

        cout << '\n';

    } while (next_permutation(arr.begin(), arr.end()));

    return 0;
}