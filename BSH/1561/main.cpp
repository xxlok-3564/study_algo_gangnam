#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    vector<int> op_time(M);

    for (int i = 0; i < M; i++)
        cin >> op_time[i];

    long long left = 1;
    long long right = 60000000000;

    long long ans;
    while (1) {
        if(left > right)
            break;

        long long mid = (left + right) / 2;
        long long people = 0;

        for (long long op : op_time)
            people += (mid / op);

        if (0 < N - people && N - people < M) {
            ans = N - people;
            break;
        }

        if (people > N)
            right = mid - 1;
        else
            left = mid + 1;

    }

    cout << ans;

    return 0;
}