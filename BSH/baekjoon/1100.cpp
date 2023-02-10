#include <iostream>

using namespace std;

int main() {

    char c;
    int ans = 0;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            cin >> c;
            if ((x + y) % 2 == 0 && c == 'F')
                ans += 1;
        }
    }

    cout << ans;

    return 0;
}