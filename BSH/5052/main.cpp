#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {

    bool finish = false;
    node *next[10] = {nullptr,};

};

void init_node(node *n) {
    n->finish = false;
    for (auto &i : n->next)
        i = nullptr;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {

        int N;
        bool fail = false;
        vector<string> str_arr;
        node root;
        init_node(&root);
        node *current = &root;

        cin >> N;

        for (int i = 0; i < N; i++) {
            string temp;
            cin >> temp;

            str_arr.emplace_back(temp);
        }

        sort(str_arr.begin(), str_arr.end());

        for (string &temp : str_arr) {

            bool maked_root = true;

            for (int str_idx = 0; str_idx < temp.size(); str_idx++) {

                if (current->finish) {
                    fail = true;
                }

                if (current->next[temp[str_idx] - '0'] == nullptr) {
                    current->next[temp[str_idx] - '0'] = new node;
                    init_node(current->next[temp[str_idx] - '0']);
                    current = current->next[temp[str_idx] - '0'];
                    maked_root = false;
                } else {
                    current = current->next[temp[str_idx] - '0'];
                }

                if (str_idx == temp.size() - 1 && maked_root)
                    fail = true;

                if (str_idx == temp.size() - 1)
                    current->finish = true;
            }
            if (fail) break;
            current = &root;
        }


        if (fail)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';

    }

    return 0;
}