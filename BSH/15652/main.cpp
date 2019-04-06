#include <iostream>

using namespace std;

int N, M;
int ans[8];

void make_ans(int start_idx, int ans_idx) {

    if (ans_idx == M) {

        for (int i = 0; i < M; i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;

    }

    for (int i = start_idx; i < N; i++) {
        ans[ans_idx] = i + 1;
        make_ans(i, ans_idx + 1);
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    make_ans(0, 0);

    return 0;
}