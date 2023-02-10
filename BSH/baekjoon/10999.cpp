#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void
update(int node, long long value, int query_left, int query_right, int node_left, int node_right,
       vector<long long> &tree,
       vector<long long> &lazy) {

    if (lazy[node] != 0) {
        tree[node] += (node_right - node_left + 1) * lazy[node];
        if (node_left != node_right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (query_right < node_left || node_right < query_left) {
        return;
    }

    if (query_left <= node_left && node_right <= query_right) {
        tree[node] += (node_right - node_left + 1) * value;
        if (node_left != node_right) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }

    update(node * 2, value, query_left, query_right, node_left, (node_left + node_right) / 2, tree, lazy);
    update(node * 2 + 1, value, query_left, query_right, (node_left + node_right) / 2 + 1, node_right, tree, lazy);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

long long query(int node, int query_left, int query_right, int node_left, int node_right, vector<long long> &tree,
                vector<long long> &lazy) {

    if (lazy[node] != 0) {
        tree[node] += (node_right - node_left + 1) * lazy[node];
        if (node_left != node_right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (query_right < node_left || node_right < query_left) {
        return 0;
    }
    if (query_left <= node_left && node_right <= query_right) {
        return tree[node];
    }
    return query(node * 2, query_left, query_right, node_left, (node_left + node_right) / 2, tree, lazy)
           + query(node * 2 + 1, query_left, query_right, (node_left + node_right) / 2 + 1, node_right, tree, lazy);


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M, K;

    cin >> N >> M >> K;

    int tree_height = (int) ceil(log2(N)) + 1;
    int node_num = (1 << tree_height) - 1;

    vector<long long> tree(node_num, 0);
    vector<long long> lazy(node_num, 0);

    long long temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        update(1, temp, i, i, 0, N - 1, tree, lazy);
    }

    for (int i = 0; i < M + K; i++) {

        int question;
        int left, right;
        long long value;
        cin >> question;

        if (question == 1) {
            cin >> left >> right >> value;
            update(1, value, left - 1, right - 1, 0, N - 1, tree, lazy);
        } else if (question == 2) {
            cin >> left >> right;
            cout << query(1, left - 1, right - 1, 0, N - 1, tree, lazy) << '\n';
        }

    }

    return 0;
}