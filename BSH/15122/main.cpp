#include <iostream>

using namespace std;

bool hasZero(int n) {

    while (n) {
        if (n % 10 == 0)
            return true;
        n /= 10;
    }

    return false;
}

int main() {
    int n, i;
    cin >> n;

    for (i = n + 1;; ++i)
        if (!hasZero(i))
            break;

    printf("%d", i);

    return 0;
}