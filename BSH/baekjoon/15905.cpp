#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int prob;
    int pen;
};

bool cmp(const node &a, const node &b) {

    if (a.prob > b.prob)
        return true;
    else if (a.prob == b.prob) {
        if (a.pen < b.pen)
            return true;
    }

    return false;
}

int main() {

    int N;

    cin >> N;

    vector<node> arr(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i].prob >> arr[i].pen;

    sort(arr.begin(), arr.end(), cmp);

    int num_prob = arr[4].prob;

    int ans = 0;
    for (int i = 5; i < N; i++)
        if (num_prob == arr[i].prob)
            ans += 1;

    cout << ans;

    return 0;
}