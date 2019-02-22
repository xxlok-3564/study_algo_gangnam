#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void f1(int n, int c, vector<int> &arr) {

    do {

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;

    } while (next_permutation(arr.begin(), arr.end()));

}

void f2(int n, int c, vector<int> &arr, vector<bool> &loc) {

    do {

        for (int i = 0; i < n; i++)
            if (loc[i])
                cout << arr[i] << " ";

        cout << endl;

    } while (next_permutation(loc.begin(), loc.end()));

}

int board[301][301];


int f3(int n, int r, vector<int> &arr) {
    if (n == r || r == 0) {
        if (board[n][r] == 0)
            return board[n][r] = 1;
        else
            return board[n][r];
    }

    int a, b;
    if (board[n - 1][r - 1])
        a = board[n - 1][r - 1];
    else
        a = f3(n - 1, r - 1, arr);

    if (board[n - 1][r])
        b = board[n - 1][r];
    else
        b = f3(n - 1, r, arr);

    return a + b;

}

void f4(){

}


int main() {

    int n, c;
    vector<int> arr;
    vector<bool> loc;
    cin >> n >> c;

    for (int i = 0; i < n; i++)
        arr.push_back(i + 1);

    loc.resize(n);
    fill(loc.end() - c, loc.end(), true);

    //f1(n, c, arr);

    cout << "-------------------------" << endl;

    //f2(n, c, arr, loc);

    cout << "-------------------------" << endl;

    cout << f3(n, c, arr) << endl;

    cout << "-------------------------" << endl;


    return 0;
}