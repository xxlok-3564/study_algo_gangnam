#include <iostream>

using namespace std;

int main() {
    int N;
    int sum = 0;
    int max = 0;

    cin >> N;

    int val;
    for (int i = 0; i < N; i++) {
        cin >> val;
        if (val > max) max = val;
        sum += val;
    }

    cout << sum - max;

    return 0;
}