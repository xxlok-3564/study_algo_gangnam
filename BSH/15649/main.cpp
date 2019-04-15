#include <iostream>
#include <vector>

using namespace std;

void make_ans(int num, int depth, int max_depth, vector<bool> &used, vector<int> &ans) {

    if (depth == max_depth) {
        for (int a : ans)
            cout << a << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= num; i++) {

        if (!used[i]) {
            used[i] = true;
            ans[depth] = i;
            make_ans(num, depth + 1, max_depth, used, ans);
            used[i] = false;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N, M;

    cin >> N >> M;

    vector<bool> used(N + 1, false);
    vector<int> ans(M);

    make_ans(N, 0, M, used, ans);

    return 0;
}