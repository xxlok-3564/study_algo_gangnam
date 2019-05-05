#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    vector<int> ans;
    cin >> N;

    vector<int> before(N + 1);
    vector<int> cnt(N + 1);

    cnt[N] = 0;

    for (int i = N - 1; i >= 1; i--) {

        cnt[i] = cnt[i + 1] + 1;
        before[i] = i + 1;

        if(i * 3 <= N && cnt[i * 3] + 1 < cnt[i]){
            cnt[i] = cnt[i * 3] + 1;
            before[i] = i * 3;
        }

        if(i * 2 <= N && cnt[i * 2] + 1< cnt[i]){
            cnt[i] = cnt[i * 2] + 1;
            before[i] = i * 2;
        }

    }

    int footprint = 1;

    while(1){

        ans.emplace_back(footprint);

        if(footprint == N)
            break;

        footprint = before[footprint];

    }

    cout << ans.size() - 1 << '\n';

    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";


    return 0;
}