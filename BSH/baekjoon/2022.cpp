#include <iostream>
#include <cmath>

using namespace std;

double err = 0.0000001;


int main() {

    double num_1;
    double num_2;

    double c;

    cin >> num_1 >> num_2 >> c;

    if (num_1 < num_2)
        swap(num_1, num_2); //num_1을 크게 세팅


    double left = 0;
    double right = num_2;

    double mid;

    //간격이 좁으면 c보다 큰 값이 나오고(mid ~ right), 간격이 크면 c보다 작은 값이 나옴(left ~ mid)
    while (1) {

        mid = (left + right) / 2;

        double can_get = sqrt((num_1 * num_1 - mid * mid)) /
                         (1 + sqrt((num_1 * num_1 - mid * mid)) / sqrt(num_2 * num_2 - mid * mid));


        double diff = can_get - c;

        if (diff >= 0) {

            if (err >= diff && diff >= 0)
                break;

            left = mid;

        } else if (diff < 0) {

            diff = -diff;
            if (err >= diff && diff >= 0)
                break;

            right = mid;

        }


    }


    cout.precision(9);

    cout << mid;

    return 0;
}