#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {

    string a;
    deque<char> b;

    cin >> a;

    for (char &c : a)
        b.push_back(c);

    if (b.size() == 1) {
        cout << "true";
        return 0;
    }

    while (!b.empty()) {
        if (b.front() == b.back()) {
            b.pop_back();
            if(!b.empty())
                b.pop_front();
        } else {
            cout << "false";
            return 0;
        }
    }

    cout << "true";

    return 0;
}