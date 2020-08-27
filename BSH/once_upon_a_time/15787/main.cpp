#include <iostream>
#include <vector>
#include <set>


using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num_train, num_order;

    cin >> num_train >> num_order;

    vector<unsigned> train(num_train, 0);

    unsigned people_all = 0;
    vector<unsigned> people(20, 0);
    people[0] = 1;
    people_all += people[0];
    for (int i = 1; i < 20; i++) {
        people[i] = (people[i - 1] << 1);
        //cout << people[i] << " ";
        people_all += people[i];
    }

    for (int i = 0; i < num_order; i++) {

        int command;
        cin >> command;

        int t_num;
        int seat;

        if (command == 1) {
            cin >> t_num >> seat;
            train[t_num - 1] |= (1 << (seat - 1));
        } else if (command == 2) {
            cin >> t_num >> seat;
            train[t_num - 1] &= (~(1 << (seat - 1)));
        } else if (command == 3) {
            cin >> t_num;
            train[t_num - 1] <<= 1;
            train[t_num - 1] &= people_all;
        } else if (command == 4) {
            cin >> t_num;
            train[t_num - 1] >>= 1;
            train[t_num - 1] &= people_all;
        }

    }

    set<unsigned> checker;

    for (unsigned t : train)
        checker.insert(t);

    cout << checker.size();

    return 0;
}