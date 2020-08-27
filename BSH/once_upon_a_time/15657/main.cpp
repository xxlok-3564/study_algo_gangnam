#include <iostream>
#include <algorithm>

using namespace std;

void rec(int start_idx, int ans_idx, int arr[8], int ans[8], int &N, int &M) {

    if (ans_idx == M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = start_idx; i < N; i++) {

        ans[ans_idx] = arr[i];
        rec(i, ans_idx + 1, arr, ans, N, M);

    }

}

int main() {

    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N, M;
    int arr[8];
    int ans[8];

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    rec(0, 0, arr, ans, N, M);


    return 0;
}