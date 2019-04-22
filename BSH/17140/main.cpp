#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node {
    int value;
    int number;
};

struct cmp {

    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second < b.second)
            return true;
        else if (a.second == b.second) {
            if (a.first < b.first)
                return true;
        }

        return false;
    }

};

void R_op(vector<vector<int>> &board, vector<vector<int>> &temp, int &x_len, int &y_len) {

    int new_x = 0;

    for (int y = 0; y < y_len; y++) {

        map<int, int> list;

        for (int x = 0; x < x_len; x++) {

            if (board[y][x]) {
                if (list.find(board[y][x]) == list.end())
                    list[board[y][x]] = 1;
                else
                    list[board[y][x]] += 1;
            }

        }

        if (2 * list.size() > new_x)
            new_x = 2 * list.size();

        vector<pair<int, int>> for_sort;

        for_sort.reserve(list.size());
        for (auto i: list)
            for_sort.emplace_back(i);

        sort(for_sort.begin(), for_sort.end(), cmp());

        int idx = 0;
        for (int i = 0; i < for_sort.size() && idx < 100; i++) {

            temp[y][idx] = for_sort[i].first;
            idx += 1;
            temp[y][idx] = for_sort[i].second;
            idx += 1;

        }
    }

    x_len = new_x;
    board = temp;

}

void L_op(vector<vector<int>> &board, vector<vector<int>> &temp, int &x_len, int &y_len) {

    int new_y = 0;

    for (int x = 0; x < x_len; x++) {

        map<int, int> list;

        for (int y = 0; y < y_len; y++) {

            if (board[y][x]) {
                if (list.find(board[y][x]) == list.end())
                    list[board[y][x]] = 1;
                else
                    list[board[y][x]] += 1;
            }

        }

        if (2 * list.size() > new_y)
            new_y = 2 * list.size();

        vector<pair<int, int>> for_sort;

        for_sort.reserve(list.size());
        for (auto i: list)
            for_sort.emplace_back(i);

        sort(for_sort.begin(), for_sort.end(), cmp());

        int idx = 0;
        for (int i = 0; i < for_sort.size() && idx < 100; i++) {

            temp[idx][x] = for_sort[i].first;
            idx += 1;
            temp[idx][x] = for_sort[i].second;
            idx += 1;

        }
    }

    y_len = new_y;
    board = temp;

}


int main() {

    int r, c, val;

    int x_len = 3;
    int y_len = 3;

    cin >> r >> c >> val;

    vector<vector<int>> board(100, vector<int>(100, 0));

    for (int y = 0; y < y_len; y++) {
        for (int x = 0; x < x_len; x++)
            cin >> board[y][x];
    }

    int ans = 0;

    for (ans = 0; ans < 101 && board[r - 1][c - 1] != val; ans++) {

        vector<vector<int>> temp(100, vector<int>(100, 0));

        if (y_len >= x_len) {
            R_op(board, temp, x_len, y_len);
        } else {
            L_op(board, temp, x_len, y_len);
        }

    }

    if (ans == 101)
        cout << "-1";
    else
        cout << ans;

    return 0;
}