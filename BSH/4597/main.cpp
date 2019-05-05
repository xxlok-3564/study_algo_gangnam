#include <iostream>

using namespace std;

int main() {

    string a;

    while (1) {

        cin >> a;

        if (a.size() == 1 && a[0] == '#')
            break;

        int _0 = 0;
        int _1 = 0;

        for (char &c : a) {
            if (c == '0')
                _0 += 1;
            else if (c == '1')
                _1 += 1;
            else if (c == 'e') {

                if (_1 % 2 == 0) {
                    a[a.size() - 1] = '0';
                    break;
                } else {
                    a[a.size() - 1] = '1';
                    break;
                }

            } else if (c == 'o') {

                if (_1 % 2 == 0) {
                    a[a.size() - 1] = '1';
                    break;
                } else {
                    a[a.size() - 1] = '0';
                    break;
                }

            }
        }

        cout << a << '\n';

    }


    return 0;
}