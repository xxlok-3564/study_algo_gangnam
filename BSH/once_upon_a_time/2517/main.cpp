#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void update_tree(int value, int node, int left_bound, int right_bound, vector<int> &tree) {

    if (left_bound <= value && value <= right_bound) {

        if (left_bound == right_bound) {
            tree[node] += 1;
            return;
        }

        int mid = left_bound + right_bound;
        mid /= 2;

        update_tree(value, node * 2, left_bound, mid, tree);
        update_tree(value, node * 2 + 1, mid + 1, right_bound, tree);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

}

//L, R: 구해야 되는 범위 // node_range_left, node_range_right:노드 담당 범위
int query(int left, int right, int node, int node_range_left, int node_range_right, vector<int> &tree) {

    if (node_range_right < left || right < node_range_left) {
        return 0;
    }

    if (left <= node_range_left && node_range_right <= right) {
        return tree[node];
    }

    int mid = node_range_left + node_range_right;
    mid /= 2;

    return query(left, right, node * 2, node_range_left, mid, tree)
           + query(left, right, node * 2 + 1, mid + 1, node_range_right, tree);

}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main() {

    int N;

    cin >> N;

    vector<pair<int, int>> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        arr[i].first = i;
    }

    sort(arr.begin(), arr.end(), cmp);

    int h = ceil(log2(N)) + 1;
    int tree_node_num = (1 << h);

    vector<int> tree(tree_node_num);

    for (int i = 0; i < N; i++) {

        cout << 1 + query(arr[i].first + 1, N - 1, 1, 0, N - 1, tree) << '\n';

        update_tree(arr[i].first, 1, 0, N - 1, tree);
    }


    return 0;
}