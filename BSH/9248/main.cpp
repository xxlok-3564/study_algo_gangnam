#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void get_suffix_arr(string &str, vector<int> &suffix_arr) {

    int cmp_loc = 1;

    vector<int> group(str.size() + 1);

    for (int i = 0; i < str.size(); i++)
        group[i] = str[i];
    group[str.size()] = -1;

    while (cmp_loc < str.size()) {

        auto cmp = [&group, cmp_loc](int a, int b) {

            if (group[a] == group[b])
                return group[a + cmp_loc] < group[b + cmp_loc];
            return group[a] < group[b];

        };

        sort(suffix_arr.begin(), suffix_arr.end(), cmp);

        vector<int> new_group(str.size() + 1);
        new_group[str.size()] = -1;
        new_group[suffix_arr[0]] = 0;

        for (int i = 0; i < str.size() - 1; i++) {
            if (cmp(suffix_arr[i], suffix_arr[i + 1])) {
                new_group[suffix_arr[i + 1]] = new_group[suffix_arr[i]] + 1;
            } else
                new_group[suffix_arr[i + 1]] = new_group[suffix_arr[i]];

        }

        group = new_group;

        cmp_loc <<= 1;
    }


}


int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> str;

    vector<int> suffix_arr(str.size());
    for (int i = 0; i < suffix_arr.size(); i++)
        suffix_arr[i] = i;

    get_suffix_arr(str, suffix_arr);

    for (int i = 0; i < suffix_arr.size(); i++)
        cout << suffix_arr[i] + 1 << " ";
    cout << '\n';

    vector<int> reverse_suffix(str.size());
    vector<int> LCP(str.size());
    for (int i = 0; i < suffix_arr.size(); i++) {
        reverse_suffix[suffix_arr[i]] = i;
    }

    int len = 0;

    for (int i = 0; i < str.size(); i++) {
        int k = reverse_suffix[i];
        if (k) {
            int j = suffix_arr[k - 1];
            while (str[j + len] == str[i + len])
                len++;
            LCP[k] = len;
            if (len)
                len--;
        }
    }

    for (int i = 0; i < str.size(); i++) {
        if (i)
            cout << LCP[i] << " ";
        else
            cout << "x ";
    }


    return 0;
}