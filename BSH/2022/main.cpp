#include <iostream>
#include <cmath>

using namespace std;

double err = 0.0000001;

double rec(double num_1, double num_2, double range_left, double range_right, double target) {





}

int main() {

    double num_1;
    double num_2;

    double target;

    double ans;

    cin >> num_1 >> num_2 >> target;

    if (num_1 < num_2)
        swap(num_1, num_2); //num_1이 커진다


    cout.precision(9);

    cout << rec(num_1, num_2, target);


    return 0;
}