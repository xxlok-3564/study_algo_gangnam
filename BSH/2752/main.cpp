#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[3];

    for (int &i : arr)
        std::cin >> i;

    sort(arr, arr + 3);

    for (int i : arr)
        cout << i << " ";

    return 0;
}