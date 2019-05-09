#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;

    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int left_ans = 1;
    int current_size = arr[0];

    for (int i = 1; i < N; i++) {
        if (arr[i] > current_size) {
            current_size = arr[i];
            left_ans += 1;
        }
    }

    cout << left_ans << '\n';

    int right_ans = 1;
    current_size = arr[N - 1];

    for (int i = arr.size() - 2; i >= 0; i--) {
        if (arr[i] > current_size){
            current_size = arr[i];
            right_ans += 1;
        }
    }

    cout << right_ans;

    return 0;
}