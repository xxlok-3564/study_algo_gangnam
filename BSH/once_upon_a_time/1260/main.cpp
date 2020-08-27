#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

void dfs(int start, vector<vector<int>> &connect_info, vector<bool> &visit) {

    cout << start << " ";

    for (int i = 0; i < connect_info[start].size(); i++) {
        if (!visit[connect_info[start][i]]) {
            visit[connect_info[start][i]] = true;
            dfs(connect_info[start][i], connect_info, visit);
        }
    }

}

int main() {

    int N, M, start_vertex;

    cin >> N >> M >> start_vertex;

    vector<vector<int>> connect_info(N + 1);

    int a, b;
    for (int i = 0; i < M; i++) {

        cin >> a >> b;

        connect_info[a].push_back(b);
        connect_info[b].push_back(a);

    }

    for (int i = 0; i < N; i++)
        sort(connect_info[i].begin(), connect_info[i].end());

    //DFS
    vector<bool> visit(N + 1, false);
    visit[start_vertex] = true;
    dfs(start_vertex, connect_info, visit);

    cout << '\n';
    //BFS

    fill(visit.begin(), visit.end(), false);
    queue<int> bfs_q;

    bfs_q.push(start_vertex);
    visit[start_vertex] = true;

    while (!bfs_q.empty()) {

        int current = bfs_q.front();
        cout << current << " ";
        bfs_q.pop();

        for (int i = 0; i < connect_info[current].size(); i++) {
            if (!visit[connect_info[current][i]]) {
                bfs_q.push(connect_info[current][i]);
                visit[connect_info[current][i]] = true;
            }
        }

    }


    return 0;
}