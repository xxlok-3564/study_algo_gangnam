#include <iostream>
#include <algorithm>

using namespace std;

void rec(int ans_idx, int arr[8], int ans[8], bool used[8], int &N, int &M) {

    if (ans_idx == M) {

        for (int i = 0; i < M; i++)
            cout << ans[i] << " ";

        cout << '\n';
        return;

    }

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            used[i] = true;
            ans[ans_idx] = arr[i];
            rec(ans_idx + 1, arr, ans, used, N, M);
            used[i] = false;
        }
    }


}

int main() {

    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N, M;
    int arr[8];
    int ans[8];
    bool used[8];

    cin >> N >> M; //N에서 M개 뽑기

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);
    fill(used, used + N, false);

    rec(0, arr, ans, used, N, M);

    return 0;
}