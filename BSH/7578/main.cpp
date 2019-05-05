#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

void update(int node, int index, int left_boundary, int right_boundary, vector<int> &tree) {

    if (left_boundary <= index && index <= right_boundary) {

        if (left_boundary == right_boundary) {
            tree[node] += 1;
            return;
        }

        tree[node] += 1;
        update(node * 2, index, left_boundary, (left_boundary + right_boundary) / 2, tree);
        update(node * 2 + 1, index, (left_boundary + right_boundary) / 2 + 1, right_boundary, tree);

    }

}

int query(int node, int query_left, int query_right, int node_left, int node_right, vector<int> &tree) {

    if (node_right < query_left || query_right < node_left)
        return 0;

    if (query_left <= node_left && node_right <= query_right)
        return tree[node];

    return query(node * 2, query_left, query_right, node_left, (node_left + node_right) / 2, tree)
           + query(node * 2 + 1, query_left, query_right, (node_left + node_right) / 2 + 1, node_right, tree);

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int num_machine;
    cin >> num_machine;

    unordered_map<int, int> machine_name_to_idx;

    int height = ceil(log2(num_machine)) + 1;
    int tree_node_num = (1 << height);
    vector<int> tree(tree_node_num, 0);

    int temp;
    for (int i = 0; i < num_machine; i++) {
        cin >> temp;
        machine_name_to_idx.insert({temp, i});
    }

    long long ans = 0;
    for (int i = 0; i < num_machine; i++) {

        cin >> temp;
        int upper_idx = machine_name_to_idx[temp];

        ans += query(1, upper_idx, num_machine - 1, 0, num_machine - 1, tree);

        update(1, upper_idx, 0, num_machine - 1, tree);

    }

    cout << ans;

    return 0;
}