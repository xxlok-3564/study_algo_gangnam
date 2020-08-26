#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;
//               0  1  2   3
int diff_x[4] = {0, 1, 0, -1};
int diff_y[4] = {-1, 0, 1, 0};
char four_dir[4] = {'U', 'R', 'D', 'L'};

struct pos {
    int x;
    int y;
    int dir;
};

struct out {
    char dir;
    int time;
};

out ans = {'a', -1};

void f1(pos &a) {
    //////
    if (a.dir == 0)
        a.dir = 1;
    else if (a.dir == 1)
        a.dir = 0;
    else if (a.dir == 2)
        a.dir = 3;
    else if (a.dir == 3)
        a.dir = 2;

}

void f2(pos &a) {
    // \\\\\\\\

    if (a.dir == 0)
        a.dir = 3;
    else if (a.dir == 1)
        a.dir = 2;
    else if (a.dir == 2)
        a.dir = 1;
    else if (a.dir == 3)
        a.dir = 0;

}

struct hf{

    bool operator() (const pos &a, const pos &b) const{

        if (a.x > b.x)
            return true;
        else if (a.x == b.x) {
            if (a.y > b.y)
                return true;
            else if (a.y == b.y) {
                if (a.dir > b.dir)
                    return true;
            }

        }

        return false;
    }

};


int main() {

    int N, M; //N:아래, M:옆
    cin >> N >> M;

    char c;

    char board[501][501];

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> c;
            board[y][x] = c;
        }
    }

    pos init_pos;

    cin >> init_pos.y >> init_pos.x;

    for (int dir = 3; dir >= 0; dir--) {

        set<pos, hf> visit;

        pos current_pos = init_pos;
        current_pos.dir = dir;
        int len = 0;
        visit.insert(current_pos);

        while (1) {

            if (current_pos.x == 0 || current_pos.x == M + 1 || current_pos.y == 0 || current_pos.y == N + 1) {
                ans.dir = four_dir[dir];
                if (len > ans.time) {
                    ans.time = len;
                }
                break;
            }

            if (board[current_pos.y][current_pos.x] == 'C') {
                if (len > ans.time) {
                    ans.time = len;
                }
                break;
            }

            if (visit.find(current_pos) == visit.end()) {
                ans.time = 250001;
                break;
            }

            current_pos.x = current_pos.x + diff_x[dir];
            current_pos.y = current_pos.y + diff_y[dir];

            if (board[current_pos.y][current_pos.x] == '/') {
                f1(current_pos);
            } else if (board[current_pos.y][current_pos.x] == '\\') {
                f2(current_pos);
            }

            len++;

        }

    }

    cout << ans.dir << endl;
    if (ans.time == 250001)
        cout << "Voyager";
    else
        cout << ans.time;


    return 0;
}