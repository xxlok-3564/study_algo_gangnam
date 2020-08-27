#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>

#define ll long long

using namespace std;

int main() {

    int N, M; // 섬의 갯수, 다리의 정보

    cin >> N >> M;

    int a, b;
    int c;

    vector<vector<pair<int, int>>> board(N + 1); // 정보 낭비 있음

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;

        board[a].emplace_back(b, c);
        board[b].emplace_back(a, c);
    }

    //시작 위치, 도착 위
    int start_loc, target_loc;
    int ans = 0;

    cin >> start_loc >> target_loc;

    int left = 1;
    int right = 1000000000;

    while (left <= right) {

        vector<bool> visit(N + 1, false);
        queue<int> bfs_q;
        int test_weight = (left + right) / 2;

        bfs_q.push(start_loc);
        visit[start_loc] = true;

        while (!bfs_q.empty()) {

            int current = bfs_q.front();
            bfs_q.pop();
            if (visit[target_loc])
                break;

            for (auto &i : board[current]) {
                if (!visit[i.first] && i.second >= test_weight) {
                    bfs_q.push(i.first);
                    visit[i.first] = true;
                }
            }

        }

        if (visit[target_loc]) {

            left = test_weight + 1;

            if (test_weight > ans)
                ans = test_weight;

        } else {

            right = test_weight - 1;

        }

    }


    cout << ans;


    return 0;
}