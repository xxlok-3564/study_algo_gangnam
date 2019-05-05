#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    using namespace std;

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int current = 1;

    for (int &num : arr) {
        if (current != num)
            break;
        current += 1;
    }

    cout << current;

    return 0;
}