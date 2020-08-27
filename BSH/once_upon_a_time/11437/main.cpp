#include <iostream>
#include <vector>

using namespace std;

void
visit_n_depth(int node, vector<int> &parent, vector<int> &depth, vector<bool> &visit, vector<vector<int>> &node_info) {

    for (int i = 0; i < node_info[node].size(); i++) {
        int next = node_info[node][i];
        if (!visit[next]) {
            visit[next] = true;
            parent[next] = node;
            depth[next] = depth[node] + 1;
            visit_n_depth(next, parent, depth, visit, node_info);
        }
    }

}

int LCA(int A, int B, vector<int> &depth, vector<int> &parent) {

    if (depth[A] > depth[B]) {
        while (depth[A] != depth[B]) {
            A = parent[A];
        }
    } else {
        while (depth[A] != depth[B]) {
            B = parent[B];
        }
    }

    while (A != B) {
        A = parent[A];
        B = parent[B];
    }

    return A;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int node;

    cin >> node;

    vector<vector<int>> node_info(node + 1);
    vector<int> parent(node + 1);
    vector<int> depth(node + 1);
    vector<bool> visit(node + 1);

    for (int i = 0; i < node - 1; i++) {

        int A, B;
        cin >> A >> B;

        node_info[A].push_back(B);
        node_info[B].push_back(A);

    }

    visit[1] = true;
    depth[1] = 1;

    visit_n_depth(1, parent, depth, visit, node_info);

    int query;
    cin >> query;

    for (int i = 0; i < query; i++) {

        int A, B;
        cin >> A >> B;

        cout << LCA(A, B, depth, parent) << '\n';

    }


    return 0;
}