#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void rec(int ans_idx, int arr[8], int ans[8], unordered_map<int, int> &number_amount, int &N, int &M) {

    if (ans_idx == M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << " ";
        cout << '\n';

        return;
    }

    for (int i = 0; i < N; i++) {
        if (number_amount[arr[i]] > 0) {
            ans[ans_idx] = arr[i];
            number_amount[arr[i]] -= 1;

            rec(ans_idx + 1, arr, ans, number_amount, N, M);

            number_amount[arr[i]] += 1;

        }
    }

}

int main() {

    int N, M;
    cin >> N >> M;

    unordered_map<int, int> number_amount;
    int arr[8];
    int arr_idx = 0;
    int ans[8];

    int getter;
    for (int i = 0; i < N; i++) {
        cin >> getter;
        if (number_amount.find(getter) == number_amount.end()) {
            number_amount[getter] = 1;
            arr[arr_idx] = getter;
            arr_idx += 1;
        } else {
            number_amount[getter] += 1;
        }
    }

    sort(arr, arr + arr_idx);

    rec(0, arr, ans, number_amount, arr_idx, M);

    return 0;
}