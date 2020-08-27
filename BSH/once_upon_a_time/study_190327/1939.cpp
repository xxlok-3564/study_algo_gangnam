#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>

#define ll long long

using namespace std;

int ans = 0;

void rec(int left, int right, vector<map<int, int>> &board, int N, int start_loc, int target_loc) {

    if (left > right)
        return;

    vector<bool> visit(N + 1, false); //bfs용 vector

    int mid = (left + right) / 2; //중량 세팅

    queue<int> bfs_q;
    visit[start_loc] = true;
    bfs_q.push(start_loc);

    while (!bfs_q.empty()) {

        int current = bfs_q.front();
        bfs_q.pop();
        if (current == target_loc)
            break;
        for (auto i = board[current].begin(); i != board[current].end(); i++) {
            if (visit[i->first] == false && i->second >= mid) {
                visit[i->first] = true;
                bfs_q.push(i->first);
            }
        }

    }

    // target_loc에 방문 가능하면
    if (visit[target_loc]) {

        if (ans < mid)
            ans = mid;

        rec(mid + 1, right, board, N, start_loc, target_loc);

    } else
        rec(left, mid - 1, board, N, start_loc, target_loc); // 중량 줄여보기


}


int main() {

    int N; // 섬의 갯수
    int M; // 다리의 정보

    cin >> N >> M;

    int a, b;
    int c;

    vector<map<int, int>> board(N + 1); // 정보 낭비 있음

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;

        board[b].insert({a, c});
        board[a].insert({b, c});

    }

    //시작 위치, 도착 위
    int start_loc, target_loc;

    cin >> start_loc >> target_loc;

    rec(1, 1000000000, board, N, start_loc, target_loc);

    cout << ans;


    return 0;
}