#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int query(int node, int query_left, int query_right, int node_left, int node_right, vector<int> &tree) {

    if (query_right < node_left || node_right < query_left)
        return 0;

    if (query_left <= node_left && node_right <= query_right)
        return tree[node];

    return query(node * 2, query_left, query_right, node_left, (node_left + node_right) / 2, tree)
           + query(node * 2 + 1, query_left, query_right, (node_left + node_right) / 2 + 1, node_right, tree);

}

void update(int node, int position, int node_left, int node_right, vector<int> &tree) {

    if (node_left == node_right) {
        tree[node] += 1;
        return;
    }

    if (node_left <= position && position <= (node_left + node_right) / 2)
        update(node * 2, position, node_left, (node_left + node_right) / 2, tree);
    else
        update(node * 2 + 1, position, (node_left + node_right) / 2 + 1, node_right, tree);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {

        int N;
        cin >> N;

        vector<int> num_to_position(N + 1);
        int tree_height = (int) ceil(log2(N)) + 1;
        int node_num = (1 << tree_height);
        vector<int> tree(node_num, 0);

        int temp;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            num_to_position[temp] = i;
        }

        long long ans = 0;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            int left = num_to_position[temp];
            int right = N - 1;
            ans += query(1, left, right, 0, N - 1, tree);
            update(1, num_to_position[temp], 0, N - 1, tree);
        }

        cout << ans << '\n';

    }

    return 0;
}