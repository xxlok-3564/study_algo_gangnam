#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    /*
     * init part: 입력 받기
     */

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;

    vector<pair<int, int>> arr(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    /*
     * 결과 계산
     */

    int ans = 0;

    int coverage_left_idx = numeric_limits<int>::min();
    int coverage_right_idx = numeric_limits<int>::min();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {

        if (coverage_right_idx < arr[i].first) {

            ans += coverage_right_idx - coverage_left_idx;

            coverage_left_idx = arr[i].first;
            coverage_right_idx = arr[i].second;

        } else {

            coverage_right_idx = max(coverage_right_idx, arr[i].second);

        }

    }

    ans += coverage_right_idx - coverage_left_idx;

    cout << ans;

    return 0;
}