#include <iostream>
#include <vector>

using namespace std;

long long memo_factorial[21];

long long num_factorial(int N) {

    if (N == 0)
        return 1;

    return memo_factorial[N] = num_factorial(N - 1) * (long long) N;

}



void rec(int depth, long long step) {




    rec(depth + 1);

}

int main() {

    /*int N, problem;

    cin >> N;
    cin >> problem;

    switch (problem) {
        case 1:
            int order;
            cin >> order;

            break;

        case 2:

            vector<int> arr;
            arr.resize(N);
            for (int i = 0; i < N; i++)
                cin >> arr[i];


            break;
    }*/

    int N;
    cin >> N;

    num_factorial(20);

    for (int i = 1; i < 21; i++)
        cout << memo_factorial[i] << endl;

    long long order;
    cin >> order;

    vector<int> num_vec;
    vector<int> ans_vec;
    num_vec.resize(N + 1);

    for(int i = 0; i < N; i++)
        num_vec[i] = i + 1;

    long long step;
    cin >> step;

    return 0;
}