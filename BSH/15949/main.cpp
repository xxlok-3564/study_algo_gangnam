#include <iostream>

#define DP_UP 0
#define DP_RIGHT 1
#define DP_DOWN 2
#define DP_LEFT 3

#define CP_RIGHT 1
#define CP_LEFT -1

#define BLACK 'X'

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

using namespace std;

int main() {
    int row, col;

    int DP = DP_DOWN;
    int CP = DP_RIGHT;

    pair<int, int> current = {0, 0};

    cin >> row >> col;

    char arr[row][col];

    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            cin >> arr[y][x];
        }
    }


    return 0;
}