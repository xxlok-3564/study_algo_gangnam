#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {

    int N, K;
    vector<int> time(200001, -1);
    queue<int> bfs_q;

    cin >> N >> K;

    bfs_q.push(N);
    time[N] = 0;

    while (!bfs_q.empty()) {

        int current = bfs_q.front();
        bfs_q.pop();

        if (current == K) {
            cout << time[current];
            break;
        }

        int new_pos[3] = {current - 1, current + 1, current * 2};

        for (int i = 0; i < 3; i++) {

            if (0 <= new_pos[i] && new_pos[i] <= 200000 && time[new_pos[i]] == -1) {

                bfs_q.push(new_pos[i]);
                time[new_pos[i]] = time[current] + 1;

//                if (new_pos[i] == K) {
//                    cout << time[new_pos[i]];
//                    return 0;
//                }
            }

        }


    }


    return 0;
}