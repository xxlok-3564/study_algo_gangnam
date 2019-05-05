#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num_element, num_command;

    cin >> num_element >> num_command;

    vector<int> sum(num_element + 1);
    sum[0] = 0;

    for (int i = 1; i <= num_element; i++) {
        int temp;
        cin >> temp;

        sum[i] = sum[i - 1] + temp;

    }

    for (int i = 0; i < num_command; i++) {
        int left, right;

        cin >> left >> right;

        cout << sum[right] - sum[left - 1] << '\n';
    }

    return 0;
}

/*
void build_segment_tree(int node, int arr_left, int arr_right, vector<int> &arr, vector<int> &tree) {

    if (arr_left == arr_right) {
        tree[node] = arr[arr_left];
        return;
    }

    int mid = (arr_left + arr_right) / 2;
    build_segment_tree(node * 2, arr_left, mid, arr, tree);
    build_segment_tree(node * 2 + 1, mid + 1, arr_right, arr, tree);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

int query(int node, int node_left, int node_right, int query_left, int query_right, vector<int> &arr, vector<int> &tree) {

    // 해당 node가 담당 query 범위 밖인 상황
    if (node_right < query_left || query_right < node_left) {
        return 0;
    }

    // 해당 node 담당 범위가 query 범위 안인 상황
    if (query_left <= node_left && node_right <= query_right) {
        return tree[node];
    }

    int l_val = query(node * 2, node_left, (node_left + node_right) / 2, query_left, query_right, arr, tree);
    int r_val = query(node * 2 + 1, (node_left + node_right) / 2 + 1, node_right, query_left, query_right, arr, tree);

    return l_val + r_val;

}

int main() {

    int num_element, num_command;

    cin >> num_element >> num_command;

    vector<int> arr(num_element);

    for (int &i : arr)
        cin >> i;

    int h = ceil(log2(arr.size())) + 1;
    int total_node = (1 << h);

    vector<int> segment_tree(total_node);

    build_segment_tree(1, 0, arr.size() - 1, arr, segment_tree);


    for (int i = 0; i < num_command; i++) {

        int boundary_left, boundary_right;

        cin >> boundary_left >> boundary_right;

        cout << query(1, 0, arr.size() - 1, boundary_left - 1, boundary_right - 1, arr, segment_tree) << '\n';

    }


    return 0;
}
 */