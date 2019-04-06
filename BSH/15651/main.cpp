#include <iostream>
#include <vector>

using namespace std;

void make_ans(int num, int depth, int max_depth, vector<int> &ans) {

    if (depth == max_depth) {
        for (int a : ans)
            cout << a << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= num; i++) {

        ans[depth] = i;
        make_ans(num, depth + 1, max_depth, ans);

    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<int> ans(M);

    make_ans(N, 0, M, ans);

    return 0;
}