#include <iostream>

using namespace std;


int main() {

    int n, m;
    int ans;
    cin >> n >> m;

    if (n == 1)
        ans = 1;
    else if (n == 2)
        ans = min(4, (m + 1) / 2);
    else {
        if (m < 7)
            ans = min(4, m);
        else
            ans = m - 2;
    }

    cout << ans;


    return 0;
}