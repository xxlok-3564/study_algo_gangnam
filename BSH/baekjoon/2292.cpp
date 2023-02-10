#include <iostream>

using namespace std;

int main() {

    int N;

    int layer = 0;
    int start_idx = 1, end_idx = 1;

    cin >> N;

    for (layer = 0;; layer++) {

        cout << layer << ":" << start_idx << " " << end_idx << '\n';

        if (start_idx <= N && N <= end_idx) {
            cout << layer + 1;
            break;
        }

        start_idx = end_idx + 1;
        end_idx = start_idx + (layer + 1) * 6 - 1;

    }


    return 0;
}