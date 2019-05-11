#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {

    if (a.first == b.first)
        return a.second < b.second;

    return a.first > b.first;

}

int get_pressed_coor(int y_val, vector<int> &arr) {
    return lower_bound(arr.begin(), arr.end(), y_val) - arr.begin();
}

void update(int node, int value, int node_left, int node_right, vector<int> &tree) {

    if (node_left == node_right) {
        tree[node] += 1;
        return;
    }

    if (node_left <= value && value <= (node_left + node_right) / 2)
        update(node * 2, value, node_left, (node_left + node_right) / 2, tree);
    else
        update(node * 2 + 1, value, (node_left + node_right) / 2 + 1, node_right, tree);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

int query(int node, int node_left, int node_right, int query_left, int query_right, vector<int> &tree) {

    if (query_right < node_left || node_right < query_left)
        return 0;

    if (query_left <= node_left && node_right <= query_right)
        return tree[node];

    return query(node * 2, node_left, (node_left + node_right) / 2, query_left, query_right, tree)
           + query(node * 2 + 1, (node_left + node_right) / 2 + 1, node_right, query_left, query_right, tree);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;

    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {

        long long ans = 0;

        int island;
        cin >> island;
        vector<pair<int, int>> arr(island);
        vector<int> coord_to_rank(island);

        for (int i = 0; i < island; i++) {
            cin >> arr[i].first >> arr[i].second;
            coord_to_rank[i] = arr[i].second;
        }

        sort(coord_to_rank.begin(), coord_to_rank.end());
        coord_to_rank.erase(unique(coord_to_rank.begin(), coord_to_rank.end()), coord_to_rank.end());

        sort(arr.begin(), arr.end(), cmp);

        int tree_height = (int) ceil(log2(coord_to_rank.size())) + 1;
        int node_num = (1 << tree_height);

        vector<int> tree(node_num, 0);

        for (auto& i : arr) {
            ans += query(1, 0, coord_to_rank.size() - 1, 0, get_pressed_coor(i.second, coord_to_rank), tree);
            update(1, get_pressed_coor(i.second, coord_to_rank), 0, coord_to_rank.size() - 1, tree);
        }

        cout << ans << '\n';

    }


    return 0;
}