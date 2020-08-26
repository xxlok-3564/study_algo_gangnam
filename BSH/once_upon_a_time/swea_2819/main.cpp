#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void rec(int before_x, int before_y, int idx, char board[][4], string &str, unordered_set<string> &ans) {

    if (idx == 7) {
        ans.insert(str);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int new_x = before_x + dx[i];
        int new_y = before_y + dy[i];

        if (0 <= new_x && new_x < 4 && 0 <= new_y && new_y < 4) {

            str[idx] = board[new_y][new_x];

            rec(new_x, new_y, idx + 1, board, str, ans);

        }

    }

}

int main() {

    int T;
    char board[4][4];
    cin >> T;

    for (int test = 0; test < T; test++) {

        unordered_set<string> ans;
        string str;
        str.resize(7);

        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++)
                cin >> board[y][x];


        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                str[0] = board[y][x];
                rec(x, y, 1, board, str, ans);
            }
        }

        cout << "#" << test + 1 << " " << ans.size() << '\n';
    }

    return 0;
}