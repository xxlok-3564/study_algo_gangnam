#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int diff_x[4] = {-1, 1, 0, 0};
int diff_y[4] = {0, 0, -1, 1};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string board;
    string new_board;
    queue<string> BFS_Q;
    unordered_map<string, int> visit;

    int zero_loc;
    int loc_y;
    int loc_x;

    char temp;

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cin >> temp;
            board += temp;
        }
    }

    BFS_Q.push(board);
    visit[board] = 0;

    while (!BFS_Q.empty()) {

        board = BFS_Q.front();
        zero_loc = board.find("0");
        loc_y = zero_loc / 3;
        loc_x = zero_loc % 3;

        for (int i = 0; i < 4; i++) {

            if (loc_y + diff_y[i] >= 0 && loc_y + diff_y[i] < 3 && loc_x + diff_x[i] >= 0 && loc_x + diff_x[i] < 3) {

                temp = board[loc_y * 3 + loc_x];
                new_board = board;
                new_board[loc_y * 3 + loc_x] = new_board[(loc_y + diff_y[i]) * 3 + (loc_x + diff_x[i])];
                new_board[(loc_y + diff_y[i]) * 3 + (loc_x + diff_x[i])] = temp;

                if (visit.find(new_board) == visit.end()) {
                    BFS_Q.push(new_board);
                    visit[new_board] = visit[board] + 1;
                }

            }

        }

        BFS_Q.pop();
    }


    if (visit.find("123456780") == visit.end())
        cout << "-1";
    else
        cout << visit["123456780"];


    return 0;
}