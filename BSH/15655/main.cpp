#include <iostream>
#include <algorithm>

using namespace std;

void rec(int ans_idx, int arr_idx, int arr[8], int ans[8], int &N, int &M) {

    if (ans_idx == M) {

        for (int i = 0; i < M; i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;
    }

    if (arr_idx == N)
        return;

    ans[ans_idx] = arr[arr_idx];
    rec(ans_idx + 1, arr_idx + 1, arr, ans, N, M);
    rec(ans_idx, arr_idx + 1, arr, ans, N, M);

}

int main() {

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