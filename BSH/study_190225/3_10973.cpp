#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<int> arr;

    cin >> N;

    arr.resize(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    if (prev_permutation(arr.begin(), arr.end()))
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
    else
        cout << "-1";

    return 0;
}