#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <limits>

using namespace std;

struct node {
    pair<int, int> loc;
    int distance;
    int broken;

    bool operator<(const node &a) {
        if (loc < a.loc) {
            return true;
        } else {
            return loc == a.loc && broken < a.broken;
        }
    }

};


int main() {

    int row, col;

    cin >> row >> col;

    vector<vector<bool>> board(row, vector<bool>(col));

    char c;

    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {

            cin >> c;

            board[y][x] = (c == '1');

        }
    }

    set<node> visit;
    queue<node> bfs_q;

    bfs_q.push({{0, 0}, 0, 0});
    visit.insert({{0, 0}, 0, 0});




    return 0;
}