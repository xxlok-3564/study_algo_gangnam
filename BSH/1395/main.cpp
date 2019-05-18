#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void
update(int node, int query_left, int query_right, int node_left, int node_right, vector<int> &tree,
       vector<bool> &lazy) {

    if (lazy[node]) {

        tree[node] = node_right - node_left + 1 - tree[node];

        if (node_left != node_right) {

            lazy[node * 2] = lazy[node * 2] ^ true;
            lazy[node * 2 + 1] = lazy[node * 2 + 1] ^ true;

        }

        lazy[node] = false;
    }

    if (query_right < node_left || node_right < query_left)
        return;

    if (query_left <= node_left && node_right <= query_right) {

        tree[node] = node_right - node_left + 1 - tree[node];

        if (node_left != node_right) {

            lazy[node * 2] = lazy[node * 2] ^ true;
            lazy[node * 2 + 1] = lazy[node * 2 + 1] ^ true;

        }

        return;
    }

    update(node * 2, query_left, query_right, node_left, (node_left + node_right) / 2, tree, lazy);
    update(node * 2 + 1, query_left, query_right, (node_left + node_right) / 2 + 1, node_right, tree, lazy);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

int
query(int node, int query_left, int query_right, int node_left, int node_right, vector<int> &tree, vector<bool> &lazy) {

    if (lazy[node]) {

        tree[node] = node_right - node_left + 1 - tree[node];

        if (node_left != node_right) {

            lazy[node * 2] = lazy[node * 2] ^ true;
            lazy[node * 2 + 1] = lazy[node * 2 + 1] ^ true;

        }

        lazy[node] = false;
    }

    if (query_right < node_left || node_right < query_left)
        return 0;

    if (query_left <= node_left && node_right <= query_right) {
        return tree[node];
    }

    return query(node * 2, query_left, query_right, node_left, (node_left + node_right) / 2, tree, lazy)
           + query(node * 2 + 1, query_left, query_right, (node_left + node_right) / 2 + 1, node_right, tree, lazy);

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;

    cin >> N >> M;

    int height = (int) ceil(log2(N)) + 1;
    int node = (1ULL << height) - 1;

    vector<int> tree(node, 0);
    vector<bool> lazy(node, false);

    //update(1, 0, N - 1, 0, N - 1, tree, lazy);

    for (int i = 0; i < M; i++) {
        int question;
        int left, right;
        cin >> question >> left >> right;

        //flip
        if (question == 0) {
            update(1, left - 1, right - 1, 0, N - 1, tree, lazy);
            //amount
        } else if (question == 1) {
            cout << query(1, left - 1, right - 1, 0, N - 1, tree, lazy) << '\n';
        }

    }

    return 0;
}