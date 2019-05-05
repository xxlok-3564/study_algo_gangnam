#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {

    pair<int, int> current = {0, 0};
    int idx = 0;
    int max_cycle = 2;
    int cycle = 0;
    int current_len = 0;
    int len = 1;

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {

        current.first += dx[idx];
        current.second += dy[idx];
        current_len += 1;

        if (len == current_len) {
            current_len = 0;
            idx += 1;
            idx %= 4;

            cycle += 1;

            if (cycle == max_cycle) {
                cycle = 0;
                len += 1;
            }
        }

    }

    cout << current.first << " " << current.second << '\n';

    return 0;
}