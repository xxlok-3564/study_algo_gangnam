#include <iostream>
#include <vector>

using namespace std;

long long memo_factorial[21];

long long make_memo_factorial(int N) {

    if (N == 0)
        return 1;

    return memo_factorial[N] = make_memo_factorial(N - 1) * (long long) N;

}

void prob1(vector<int> &orig, vector<int> &ans, int idx, int N, long long &order) {

    if (idx == N - 1) {
        ans[idx] = orig[0];
        return;

    }

    int temp = order / memo_factorial[N - 1 - idx];
    ans[idx] = orig[temp];
    orig.erase(orig.begin() + temp);
    order -= (temp * memo_factorial[N - 1 - idx]);

    prob1(orig, ans, idx + 1, N, order);

}

void prob2(vector<int> &orig, vector<int> &prob, int idx, int N, long long &ans) {

    if (idx == N - 1)
        return;

    for (int i = 0; i < orig.size(); i++) {
        if (orig[i] == prob[idx]) {
            ans += i * memo_factorial[N - 1 - idx];
            orig.erase(orig.begin() + i);
            break;
        }
    }

    prob2(orig, prob, idx + 1, N, ans);

}

int main() {

    int N, problem;
    vector<int> orig_vec;
    vector<int> result_vec;

    cin >> N >> problem;

    make_memo_factorial(N);

    orig_vec.resize(N);
    result_vec.resize(N);

    for (int i = 0; i < N; i++)
        orig_vec[i] = i + 1;

    switch (problem) {
        case 1:
            long long order;
            cin >> order;
            order -= 1;

            prob1(orig_vec, result_vec, 0, N, order);

            for (int i = 0; i < N; i++)
                cout << result_vec[i] << " ";

            break;

        case 2:

            long long ans = 0;

            for (int i = 0; i < N; i++)
                cin >> result_vec[i];

            prob2(orig_vec, result_vec, 0, N, ans);

            cout << ans + 1;

            break;
    }

    return 0;
}