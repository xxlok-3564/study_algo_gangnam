#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct trie_node {

    bool fin;
    unsigned char cnt;
    vector<trie_node *> next;

    trie_node() : fin(false), cnt(0), next(vector<trie_node *>('z' - 'a' + 1, nullptr)) {
    }

};

struct trie {

    trie_node *start;

    static void clear(trie_node *current) {

        for (auto &i : current->next) {
            if (i != nullptr)
                clear(i);
        }
        delete current;

    }

    trie() {
        start = new trie_node;
    }

    ~trie() {
        clear(start);
    }

    void insert(string &str) {

        trie_node *current = start;

        for (int i = 0; i < str.size(); i++) {

            if (current->next[str[i] - 'a'] == nullptr) {
                current->next[str[i] - 'a'] = new trie_node;
                current->cnt += 1;
            }

            current = current->next[str[i] - 'a'];

            if (i == str.size() - 1) {
                current->fin = true;
            }
        }

    }

    int get_cost(string &str) { //strlen == 1? strlen > 1?

        trie_node *current = start;

        int cost = 0;

        for (int i = 0; i < str.size(); i++) {

            if (i == 0) {
                cost += 1;
            } else if (current->fin || current->cnt > 1)
                cost += 1;

            current = current->next[str[i] - 'a'];
        }

        return cost;

    }

};

int main() {

    int N;

    while (cin >> N) {

        string str;
        vector<string> str_arr;
        trie *trie_struct = new trie;

        for (int i = 0; i < N; i++) {
            cin >> str;
            str_arr.push_back(str);
            trie_struct->insert(str);
        }

        double ans = 0;

        for (auto & i : str_arr) {
            int cost = trie_struct->get_cost(i);
            ans += cost;
        }

        cout << fixed;
        cout.precision(2);
        cout << ans / (double) str_arr.size() << '\n';

        delete trie_struct;

    }

    return 0;
}