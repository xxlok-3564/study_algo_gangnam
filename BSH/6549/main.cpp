#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int init_tree(int node, int coverage_left, int coverage_right, vector<int> &arr, vector<int> &tree) {

    if (coverage_left == coverage_right) {
        tree[node] = coverage_left;
        return tree[node];
    }

    int left = init_tree(node * 2, coverage_left, (coverage_left + coverage_right) / 2, arr, tree);
    int right = init_tree(node * 2 + 1, (coverage_left + coverage_right) / 2 + 1, coverage_right, arr, tree);

    return tree[node] = arr[left] < arr[right] ? left : right;

}

int
query(int node, int query_left, int query_right, int node_left, int node_right, vector<int> &arr, vector<int> &tree) {

    if (node_right < query_left || query_right < node_left)
        return -1;

    if (query_left <= node_left && node_right <= query_right)
        return tree[node];

    int left = query(node * 2, query_left, query_right, node_left, (node_left + node_right) / 2, arr, tree);
    int right = query(node * 2 + 1, query_left, query_right, (node_left + node_right) / 2 + 1, node_right, arr, tree);

    if (left == -1)
        return right;
    else if (right == -1)
        return left;
    else {

        if (arr[left] < arr[right])
            return left;
        else
            return right;
    }

}

long long largest(int left, int right, vector<int> &arr, vector<int> &tree) {

    int min_height_idx = query(1, left, right, 0, arr.size() - 1, arr, tree);
    long long area = (long long) (right - left + 1) * (long long) arr[min_height_idx];

    if (left <= min_height_idx - 1) {

        long long temp = largest(left, min_height_idx - 1, arr, tree);

        if (area < temp)
            area = temp;

    }

    if (min_height_idx + 1 <= right) {

        long long temp = largest(min_height_idx + 1, right, arr, tree);

        if (area < temp)
            area = temp;

    }

    return area;

}

int main() {
    // 막대 높이 0 ≤ h ≤ 1,000,000,000
    // 막대 갯수 1 ≤ n ≤ 100,000

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {

        int n;

        cin >> n;

        if (n == 0)
            break;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int tree_height = ceil(log2(n)) + 1;
        int tree_node_num = (1 << tree_height);
        vector<int> seg_tree(tree_node_num, -1);

        init_tree(1, 0, n - 1, arr, seg_tree);

        cout << largest(0, arr.size() - 1, arr, seg_tree) << '\n';

    }


    return 0;
}