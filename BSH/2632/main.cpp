#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int want_pizza_size;
    cin >> want_pizza_size;

    int pizza_a_pieces, pizza_b_pieces;

    cin >> pizza_a_pieces >> pizza_b_pieces;

    vector<int> pizza_a(pizza_a_pieces);
    vector<int> pizza_b(pizza_b_pieces);

    for (int i = 0; i < pizza_a_pieces; i++)
        cin >> pizza_a[i];

    for (int i = 0; i < pizza_b_pieces; i++)
        cin >> pizza_b[i];

    vector<int> pizza_a_case;
    vector<int> pizza_b_case;

    //pizza 조각 세기
    pizza_a_case.push_back(0);
    pizza_b_case.push_back(0);

    int first_pizza_size = pizza_a[0];
    pizza_a_case.push_back(first_pizza_size);

    for (int end_point = 1; end_point < pizza_a.size(); end_point++) {
        first_pizza_size += pizza_a[end_point];
        pizza_a_case.push_back(first_pizza_size);
    }

    for (int start_point = 1; start_point < pizza_a.size(); start_point++) {
        int pizza_size = pizza_a[start_point];
        pizza_a_case.push_back(pizza_size);
        for (int end_point = (start_point + 1) % pizza_a.size();
             end_point != start_point - 1; end_point = (end_point + 1) % pizza_a.size()) {
            pizza_size += pizza_a[end_point];
            pizza_a_case.push_back(pizza_size);
        }

    }

    first_pizza_size = pizza_b[0];
    pizza_b_case.push_back(first_pizza_size);

    for (int end_point = 1; end_point < pizza_b.size(); end_point++) {
        first_pizza_size += pizza_b[end_point];
        pizza_b_case.push_back(first_pizza_size);
    }

    for (int start_point = 1; start_point < pizza_b.size(); start_point++) {
        int pizza_size = pizza_b[start_point];
        pizza_b_case.push_back(pizza_size);
        for (int end_point = (start_point + 1) % pizza_b.size();
             end_point != start_point - 1; end_point = (end_point + 1) % pizza_b.size()) {
            pizza_size += pizza_b[end_point];
            pizza_b_case.push_back(pizza_size);
        }

    }

    sort(pizza_a_case.begin(), pizza_a_case.end());
    sort(pizza_b_case.begin(), pizza_b_case.end());

    long long ans = 0;

    for (int i = 0; i < pizza_a_case.size(); i++) {
        if (pizza_a_case[i] > want_pizza_size)
            break;
        auto a = equal_range(pizza_b_case.begin(), pizza_b_case.end(), want_pizza_size - pizza_a_case[i]);
        ans += distance(a.first, a.second);

    }

    cout << ans;


    return 0;
}