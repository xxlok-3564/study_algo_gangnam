#include <iostream>
#include <vector>

using namespace std;

int N, M; // N개중 M개 뽑기

void rec(int arr_idx, int ans_idx, vector<int> &arr, vector<int> &ans) {

    if (ans_idx == M) {
        for (int num: ans)
            cout << num << " ";
        cout << '\n';

        return;
    }

    if (arr_idx == N) {
        return;
    }

    ans[ans_idx] = arr[arr_idx];
    rec(arr_idx + 1, ans_idx + 1, arr, ans);
    rec(arr_idx + 1, ans_idx, arr, ans);

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<int> arr(N);
    vector<int> ans(M);

    for (int i = 0; i < N; i++)
        arr[i] = i + 1;

    rec(0, 0, arr, ans);

    return 0;
}