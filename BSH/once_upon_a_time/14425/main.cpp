#include <iostream>
#include <vector>

using namespace std;

struct trie_node {

    bool fin = false;
    bool more = false;

    vector<trie_node *> next;

    trie_node() : fin(false), more(false), next(vector<trie_node *>('z' - 'a' + 1, nullptr)) {
    }

};

struct trie {

    trie_node start;

    void insert(string &str) {

        trie_node *current = &start;

        for (int i = 0; i < str.size(); i++) {

            if (current->next[str[i] - 'a'] == nullptr)
                current->next[str[i] - 'a'] = new trie_node;

            current = current->next[str[i] - 'a'];

            if (i == str.size() - 1)
                current->fin = true;

        }

    }

    bool find(string &str) {

        trie_node *current = &start;

        for (char &i : str) {
            if (current->next[i - 'a'] == nullptr)
                return false;
            current = current->next[i - 'a'];
        }

        return current->fin;
    }

};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    int ans = 0;
    string a;
    trie trie_struct;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> a;
        trie_struct.insert(a);
    }

    for (int i = 0; i < M; i++) {
        cin >> a;
        if (trie_struct.find(a)) ans += 1;
    }

    cout << ans;

    return 0;
}