#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool score = false;
    bool check[m][n];

    while (1) {
        score = false;
        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++)
                check[y][x] = false;

        for (int y = 0; y < m - 1; y++) {
            for (int x = 0; x < n - 1; x++) {
                if (board[y][x] == board[y][x + 1] && board[y + 1][x] == board[y + 1][x + 1] &&
                    board[y][x] == board[y + 1][x]) {
                    if (board[y][x] != '0') {
                        check[y][x] = check[y][x + 1] = check[y + 1][x] = check[y + 1][x + 1] = true;
                        score = true;
                    }
                }
            }
        }

        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++)
                if (check[y][x] == true) {
                    board[y][x] = '0';
                    answer += 1;
                }

        if (score == false)
            break;


        for (int x = n - 1; x >= 0; x--) {
            for (int y = m - 1; y >= 0; y--) {
                if (board[y][x] == '0') {
                    for (int new_y = y - 1; new_y >= 0; new_y--) {
                        if (board[new_y][x] != '0') {
                            board[y][x] = board[new_y][x];
                            board[new_y][x] = '0';
                            break;
                        }
                    }
                }
            }
        }


    }


    return answer;
}

int main() {

    string a = "aaa";
    cout << (a[0] == a[1] == a[2]) << endl;


    cout << solution(4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"});


    return 0;
}