#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    vector<int> arr;

    cin >> N;
    arr.resize(N + 1);

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 0; i < N - 1; i++)
        arr[i + 2] = arr[i + 1] + arr[i];

    cout << arr[N];

    return 0;
}