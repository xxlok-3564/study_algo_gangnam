#include <iostream>
#include <queue>

using namespace std;

struct aa {
    int ans;
    bool type;
};

int main() {

    int N;
    cin >> N;

    int broken;
    cin >> broken;

    vector<bool> broken_list(10, false);

    for (int i = 0; i < broken; i++) {
        int temp;
        cin >> temp;
        broken_list[temp] = true;
    }

    queue<aa> bfs_q;
    vector<int> num_visit(1000001, -1);
    vector<int> updown_visit(1000001, -1);

    //위 아래로 오는 것은 type이 0, 숫자로 오는 건 1

    updown_visit[100] = 0;
    bfs_q.push({100, 0});

    for (int i = 0; i < 10; i++) {
        if (!broken_list[i]) {
            bfs_q.push({i, 1});
            num_visit[i] = 1;
        }
    }


    while (!bfs_q.empty()) {
        aa current = bfs_q.front();
        bfs_q.pop();

        if (num_visit[N] != -1 && updown_visit[N] != -1) {
            cout << min(num_visit[N], updown_visit[N]);
            return 0;
        }

        aa new_num;
        if (current.type == 0) {

            new_num = current;
            new_num.ans += 1;
            if (0 <= new_num.ans && new_num.ans <= 1000000 && updown_visit[new_num.ans] == -1) {

                bfs_q.push(new_num);
                updown_visit[new_num.ans] = updown_visit[current.ans] + 1;

            }

            new_num = current;
            new_num.ans -= 1;
            if (0 <= new_num.ans && new_num.ans <= 1000000 && updown_visit[new_num.ans] == -1) {

                bfs_q.push(new_num);
                updown_visit[new_num.ans] = updown_visit[current.ans] + 1;

            }


        } else if (current.type == 1) {

            new_num = current;
            new_num.ans += 1;
            new_num.type = 0;
            if (0 <= new_num.ans && new_num.ans <= 1000000 && updown_visit[new_num.ans] == -1) {

                bfs_q.push(new_num);
                updown_visit[new_num.ans] = num_visit[current.ans] + 1;

            }

            new_num = current;
            new_num.ans -= 1;
            new_num.type = 0;
            if (0 <= new_num.ans && new_num.ans <= 1000000 && updown_visit[new_num.ans] == -1) {

                bfs_q.push(new_num);
                updown_visit[new_num.ans] = num_visit[current.ans] + 1;

            }

            for (int i = 0; i < 10; i++) {

                if (!broken_list[i]) {
                    new_num = current;
                    new_num.ans = new_num.ans * 10 + i;
                    if (0 <= new_num.ans && new_num.ans <= 1000000 && num_visit[new_num.ans] == -1) {

                        bfs_q.push(new_num);
                        num_visit[new_num.ans] = num_visit[current.ans] + 1;

                    }

                }

            }

        }

    }

    if (num_visit[N] == -1)
        cout << updown_visit[N];
    else
        cout << min(updown_visit[N], num_visit[N]);


    return 0;
}