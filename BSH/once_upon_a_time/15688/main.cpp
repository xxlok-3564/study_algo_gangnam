#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';


    return 0;
}*/

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int zero = (1000000 * 2 + 1) / 2;

    int N;
    cin >> N;

    vector<int> arr(1000000 * 2 + 1, 0);

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr[temp + zero] += 1;
    }

    for (int i = 0; i < arr.size(); i++) {
        while (arr[i]) {
            cout << i - zero << '\n';
            arr[i] -= 1;
        }
    }

    return 0;
}