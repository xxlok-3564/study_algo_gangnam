#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct union_find {

    vector<int> parent;
    vector<int> rank;       // tree의 높이
    vector<int> num_node;

    union_find() : parent(200001), rank(200001, 1), num_node(200001, 1) {
        for (int i = 0; i < 200001; i++) {
            parent[i] = i;
        }
    }

    void uni(int x, int y) {
        x = find(x); // x의 최고 위
        y = find(y); // y의 최고 위

        if (x == y) {
            cout << num_node[x] << '\n';
            return;
        }

        if (rank[x] < rank[y]) {
            parent[x] = y;
            num_node[y] += num_node[x];
            cout << num_node[y] << '\n';
        } else {
            parent[y] = x;
            num_node[x] += num_node[y];
            cout << num_node[x] << '\n';
        }

        if (rank[x] == rank[y])
            rank[x]++;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {

        unordered_map<string, int> id_to_idx;
        int idx = 0;

        union_find uni;

        int N;
        cin >> N;

        string a, b;

        for (int i = 0; i < N; i++) {

            cin >> a >> b;

            if (id_to_idx.find(a) == id_to_idx.end()) {
                id_to_idx[a] = idx;
                idx++;
            }

            if (id_to_idx.find(b) == id_to_idx.end()) {
                id_to_idx[b] = idx;
                idx++;
            }

            int a_idx, b_idx;

            a_idx = id_to_idx[a];
            b_idx = id_to_idx[b];

            uni.uni(a_idx, b_idx);

        }


    }

    return 0;
}