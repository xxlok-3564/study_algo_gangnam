#include <iostream>
#include <vector>

#define MAX_DEPTH 20

using namespace std;

void get_parent(int node, vector<bool> &visit, vector<int> &depth, vector<vector<pair<int, int>>> &node_info,
                vector<vector<pair<int, int>>> &ancestor) {

    for (int i = 0; i < node_info[node].size(); i++) {
        int next = node_info[node][i].first;
        if (!visit[next]) {
            visit[next] = true;
            depth[next] = depth[node] + 1;
            ancestor[next][0].first = node;
            ancestor[next][0].second = node_info[node][i].second;
            get_parent(next, visit, depth, node_info, ancestor);
        }
    }

}

void get_ancestor(int N, vector<vector<pair<int, int>>> &ancestor) {

    for (int depth = 1; depth < MAX_DEPTH; depth++) {
        for (int node = 1; node <= N; node++) {
            ancestor[node][depth].first = ancestor[ancestor[node][depth - 1].first][depth - 1].first;
            if (ancestor[node][depth].first == 0) {
                ancestor[node][depth].second = 0;
            } else {
                ancestor[node][depth].second =
                        ancestor[node][depth - 1].second + ancestor[ancestor[node][depth - 1].first][depth - 1].second;
            }
        }
    }

}

int get_distance(int A, int B, vector<int> &depth, vector<vector<pair<int, int>>> &ancestor) {

    int distance = 0;

    if (depth[A] < depth[B])
        swap(A, B);

    for (int d = MAX_DEPTH - 1; d >= 0; d--) {
        if (depth[A] - depth[B] >= (1 << d)) {
            distance += ancestor[A][d].second;
            A = ancestor[A][d].first;
        }
    }

    //cout << ancestor[A][0].first << '\n';

    if (A == B)
        return distance;

    for (int i = MAX_DEPTH - 1; i >= 0; i--) {
        if (ancestor[A][i] != ancestor[B][i]) {
            distance += ancestor[A][i].second;
            distance += ancestor[B][i].second;

            A = ancestor[A][i].first;
            B = ancestor[B][i].first;
        }

    }

    distance += ancestor[A][0].second;
    distance += ancestor[B][0].second;

    //cout << ancestor[A][0].first << '\n';

    return distance;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;

    //기본 입력을 받음
    vector<vector<pair<int, int>>> node_info(N + 1);

    //ancestor[node][parent]: {node의 2^parent, node의 2^parent까지의 거리}
    vector<vector<pair<int, int>>> ancestor(N + 1, vector<pair<int, int>>(MAX_DEPTH, {0, 0}));
    vector<bool> visit(N + 1, 0);
    vector<int> depth(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int A, B, len;
        cin >> A >> B >> len;
        node_info[A].push_back({B, len});
        node_info[B].push_back({A, len});
    }

    visit[1] = true;
    depth[1] = 1;

    get_parent(1, visit, depth, node_info, ancestor);
    get_ancestor(N, ancestor);

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        cout << get_distance(A, B, depth, ancestor) << '\n';
    }

    return 0;


}