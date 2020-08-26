#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void rec(int ans_idx, int arr[8], int ans[8], int &arr_idx, int &M) {

    if (ans_idx == M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 0; i < arr_idx; i++) {
        ans[ans_idx] = arr[i];
        rec(ans_idx + 1, arr, ans, arr_idx, M);
    }

}

int main() {

    int N, M;
    int init_arr[8];
    int arr[8];
    int arr_idx = 0;
    int ans[8];
    set<int> exist;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> init_arr[i];
        if (exist.find(init_arr[i]) == exist.end()) {
            exist.insert(init_arr[i]);
            arr[arr_idx] = init_arr[i];
            arr_idx += 1;
        }
    }

    sort(arr, arr + arr_idx);

    rec(0, arr, ans, arr_idx, M);

    return 0;
}