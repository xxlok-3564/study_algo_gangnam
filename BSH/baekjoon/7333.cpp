#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {

    int T;

    cin >> T;

    for (int testcase = 1; testcase <= T; testcase++) {

        int N;
        cin >> N;

        deque<int> arr;

        int temp;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            arr.push_back(temp);
        }

        sort(arr.begin(), arr.end());

        int ans = 0;
        while (!arr.empty()) {

            int base_size = arr.back();
            arr.pop_back();
            int layer = 1;

            while (!arr.empty() && layer * base_size < 50) {
                arr.pop_front();
                layer += 1;
            }

            if (base_size * layer >= 50)
                ans += 1;

        }

        cout << "#" << testcase << " " << ans << '\n';

    }


    return 0;
}