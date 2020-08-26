#include <iostream>
#include <vector>

using namespace std;

void
rec(int depth, int current, int &try_cnt, int &success, int &cycle_start, bool &can_put, vector<int> &arr,
    vector<int> &visit) {

    visit[current] = try_cnt;

    if (visit[arr[current]]) {

        if (visit[arr[current]] == try_cnt) {

            success += 1;
            cycle_start = arr[current];
            can_put = true;
            return;

        } else {
            cycle_start = 0;
            can_put = false;
            return;
        }

    } else {

        rec(depth + 1, arr[current], try_cnt, success, cycle_start, can_put, arr, visit);

        if (current == cycle_start) {
            success += 1;
            can_put = false;
        }

        if (can_put)
            success += 1;
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int test = 0; test < T; test++) {

        int n;
        cin >> n;
        vector<int> arr(n + 1);
        vector<int> visit(n + 1, 0);
        int try_cnt = 1;
        int success = 0;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (arr[i] == i) {
                visit[i] = try_cnt;
                success += 1;
                try_cnt += 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                int cycle_start = 0;
                bool can_put = false;
                rec(1, i, try_cnt, success, cycle_start, can_put, arr, visit);
                try_cnt += 1;
            }
        }

        cout << n - success << '\n';

    }

    return 0;
}