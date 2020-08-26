#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int num_line;
    cin >> num_line;

    int temp[3];
    int min_ans[3] = {0, 0, 0};
    int max_ans[3] = {0, 0, 0};

    for (int line = 0; line < num_line; line++) {

        int min_temp[3];
        int max_temp[3];

        cin >> min_temp[0] >> min_temp[1] >> min_temp[2];
        max_temp[0] = min_temp[0];
        max_temp[1] = min_temp[1];
        max_temp[2] = min_temp[2];

        min_temp[0] = min_temp[0] + min(min_ans[0], min_ans[1]);
        min_temp[1] = min_temp[1] + min(min_ans[0], min(min_ans[1], min_ans[2]));
        min_temp[2] = min_temp[2] + min(min_ans[1], min_ans[2]);

        max_temp[0] = max_temp[0] + max(max_ans[0], max_ans[1]);
        max_temp[1] = max_temp[1] + max(max_ans[0], max(max_ans[1], max_ans[2]));
        max_temp[2] = max_temp[2] + max(max_ans[1], max_ans[2]);

        for (int idx = 0; idx < 3; idx++) {
            max_ans[idx] = max_temp[idx];
            min_ans[idx] = min_temp[idx];
        }

    }

    cout << max(max_ans[0], max(max_ans[1], max_ans[2])) << " " << min(min_ans[0], min(min_ans[1], min_ans[2]));


    return 0;
}