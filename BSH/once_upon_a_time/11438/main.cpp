#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 100000
using namespace std;

void
dfs(int here, vector<bool> &visit, vector<int> &depth, vector<vector<int>> &parent, vector<vector<int>> &node_info) {

    for (int i = 0; i < node_info[here].size(); i++) {
        int next = node_info[here][i];
        if (!visit[next]) {
            visit[next] = true;
            parent[next][0] = here;
            depth[next] = depth[here] + 1;
            dfs(next, visit, depth, parent, node_info);
        }
    }

}

void find_ancestor(vector<vector<int>> &parent, int num_node) {
    for (int Ancestor = 1; Ancestor < 21; Ancestor++) {
        for (int node = 1; node <= num_node; node++) {
            parent[node][Ancestor] = parent[parent[node][Ancestor - 1]][Ancestor - 1];
        }
    }
}

int lca(int A, int B, vector<int> &depth, vector<vector<int>> &parent) {
    if (depth[A] > depth[B])
        swap(A, B);
    for (int i = 20; i >= 0; i--) {
        if (depth[B] - depth[A] >= (1 << i))
            B = parent[B][i];
    }

    if (A == B)
        return A;

    for (int i = 20; i >= 0; i--) {
        if (parent[A][i] != parent[B][i]) {
            A = parent[A][i];
            B = parent[B][i];
        }
    }
    return parent[A][0];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    vector<vector<int>> node_info(N + 1);
    vector<bool> visit(N + 1);
    vector<int> depth(N + 1);
    vector<vector<int>> parent(N + 1, vector<int>(21, 0));

    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        node_info[A].push_back(B);
        node_info[B].push_back(A);
    }

    visit[1] = true;
    depth[1] = 1;

    dfs(1, visit, depth, parent, node_info);
    find_ancestor(parent, N);

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        cout << lca(A, B, depth, parent) << '\n';

    }

    return 0;
}