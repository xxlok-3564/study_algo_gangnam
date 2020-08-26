#include <iostream>
#include <vector>
#include <limits>
#include <array>
#include <queue>

using namespace std;

int night_dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int night_dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};

int bishop_dx[4] = {1, 1, -1, -1};
int bishop_dy[4] = {-1, 1, -1, 1};

int get_night_cost(array<int, 2> &before, array<int, 2> &after, int &N) {

    vector<vector<int>> visit(N, vector<int>(N, -1));
    queue<array<int, 2>> bfs_q;

    visit[before[1]][before[0]] = 0;
    bfs_q.push(before);

    while (!bfs_q.empty()) {

        array<int, 2> current = bfs_q.front();
        bfs_q.pop();
        if (after[0] == current[0] && after[1] == current[1])
            return visit[current[1]][current[0]];

        for (int i = 0; i < 8; i++) {

            array<int, 2> new_pos = {current[0] + night_dx[i], current[1] + night_dy[i]};

            if (0 <= new_pos[0] && new_pos[0] < N && 0 <= new_pos[1] && new_pos[1] < N &&
                visit[new_pos[1]][new_pos[0]] == -1) {
                visit[new_pos[1]][new_pos[0]] = visit[current[1]][current[0]] + 1;
                bfs_q.push(new_pos);
            }

        }

    }

    return -1;

}

bool in_boundary(array<int, 2> &loc, int &N) {

    return 0 <= loc[0] && loc[0] < N && 0 <= loc[1] && loc[1] < N;

}

int get_bishop_cost(array<int, 2> &before, array<int, 2> &after, int &N) {

    if (((before[0] + before[1]) % 2) != ((after[0] + after[1]) % 2))
        return -1;

    array<int, 2> cost[4] = {before, before, before, before};

    while (1) {

        if (cost[0] == after || cost[1] == after || cost[2] == after || cost[3] == after)
            return 1;

        if (!in_boundary(cost[0], N) && !in_boundary(cost[1], N) && !in_boundary(cost[2], N) &&
            !in_boundary(cost[3], N))
            break;

        for (int i = 0; i < 4; i++) {
            cost[i][0] += bishop_dx[i];
            cost[i][1] += bishop_dy[i];
        }

    }

    return 2;

}

int get_rook_cost(array<int, 2> &before, array<int, 2> &after) {

    if (before[0] == before[1] || after[0] == after[1])
        return 1;

    return 2;
}

int cost_max;

int main() {

    int N;
    cin >> N;

    cost_max = 2 * N * N + 10;

    vector<array<int, 2>> location(N * N + 1);
    vector<array<int, 3>> time(N * N + 1, {cost_max, cost_max, cost_max});

    int temp;
    for (int idx = 0; idx < N * N; idx++) {
        cin >> temp;
        location[temp][0] = idx % N;
        location[temp][1] = idx / N;
    }

    time[1][0] = 0;
    time[1][1] = 0;
    time[1][2] = 0;

    for (int idx = 2; idx <= N * N; idx++) {

        int cost[3];
        int bishop_cost = get_bishop_cost(location[idx - 1], location[idx], N);
        int night_cost = get_night_cost(location[idx - 1], location[idx], N);
        int rook_cost = get_rook_cost(location[idx - 1], location[idx]);

        if (bishop_cost == -1)
            time[idx][0] = cost_max;
        else {

            for (int i = 0; i < 3; i++) {
                if (time[idx - 1][i] == cost_max)
                    cost[i] = cost_max;
                else {
                    if (i == 0)
                        cost[i] = time[idx - 1][i] + bishop_cost;
                    else
                        cost[i] = time[idx - 1][i] + bishop_cost + 1;
                }
            }
            time[idx][0] = min(min(cost[0], cost[1]), cost[2]);
        }


        if (night_cost == -1)
            time[idx][1] == cost_max;
        else {
            for (int i = 0; i < 3; i++) {
                if (time[idx - 1][i] == cost_max)
                    cost[i] = cost_max;
                else {

                    if (i == 1)
                        cost[i] = time[idx - 1][i] + night_cost;
                    else
                        cost[i] = time[idx - 1][i] + night_cost + 1;

                }
            }
            time[idx][1] = min(min(cost[0], cost[1]), cost[2]);
        }


        for (int i = 0; i < 3; i++) {
            if (time[idx - 1][i] == cost_max)
                cost[i] = cost_max;
            else {

                if (i == 2)
                    cost[i] = time[idx - 1][i] + rook_cost;
                else
                    cost[i] = time[idx - 1][i] + rook_cost + 1;

            }
        }

        time[idx][2] = min(min(cost[0], cost[1]), cost[2]);
    }

    cout << min(min(time[N * N][0], time[N * N][1]), time[N * N][2]);

    return 0;
}