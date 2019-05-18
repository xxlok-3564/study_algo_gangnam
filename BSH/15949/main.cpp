#include <iostream>
#include <vector>

using namespace std;

int main() {

    int row, col;

    cin >> row >> col;

    vector<vector<char>> board(row, vector<char>(col));

    char temp;
    for (int y = 0; y < row; y++)
        for (int x = 0; x < col; x++)
            cin >> temp;




    return 0;
}