#include <iostream>
#include <vector>

using namespace std;

vector<int> path[1001];

int get_cost(int node, vector<int> &cost_table, vector<int> &cost_memo) {

    if (cost_memo[node] != -1)
        return cost_memo[node];

    int max = 0;
    int temp;
    for (int i = 0; i < path[node].size(); i++) {
        temp = get_cost(path[node][i], cost_table, cost_memo);
        if (temp > max)
            max = temp;
    }

    return cost_memo[node] = max + cost_table[node];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_test;
    cin >> num_test;

    for (int t = 0; t < num_test; t++) {

        int N, K;
        int target;

        cin >> N >> K;

        vector<int> cost_table(N + 1);
        vector<int> cost_memo(N + 1, -1);
        for (int i = 1; i <= N; i++)
            path[i].clear();

        for (int i = 1; i <= N; i++)
            cin >> cost_table[i];

        int a, b;
        for (int i = 0; i < K; i++) {
            cin >> a >> b;
            path[b].push_back(a);
        }

        cin >> target;

        cout << get_cost(target, cost_table, cost_memo) << '\n';

    }


    return 0;
}