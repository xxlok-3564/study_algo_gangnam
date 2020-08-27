#include <iostream>
#include <vector>

using namespace std;

bool board[52][52];
int ans = 4;
int N, M, H;

struct pos {
    int x;
    int y;
};

//vector<pos> put_pos;

bool complete() {

    bool fail = false;

    for (int x = 1; x <= N; x++) {
        int first_location = x;
        for (int y = 1; y <= H; y++) {

            if (board[y][first_location])
                first_location += 1;
            else if (board[y][first_location - 1])
                first_location -= 1;

        }
        if (first_location != x) {
            fail = true;
            break;
        }
    }

    return !fail;
}

bool valid_pos(pos temp) {

    return !board[temp.y][temp.x - 1] && !board[temp.y][temp.x] && !board[temp.y][temp.x + 1];

}

pos get_next_ladder(pos prev_ladder) {

    pos temp = prev_ladder;

    while (1) {

        temp.y += 1;
        if (temp.y > H) {
            temp.y = 1;
            temp.x += 1;
        }

        if (valid_pos(temp))
            break;

        if (temp.y == 1 && temp.x == N)
            break;
    }

    return temp;
}

void rec(int depth, pos prev_ladder) {


    pos current_ladder = get_next_ladder(prev_ladder);

    while (!(current_ladder.y == 1 && current_ladder.x == N)) {

        board[current_ladder.y][current_ladder.x] = true;
        /*put_pos.push_back({current_ladder.x, current_ladder.y});
        for(int i= 0; i < put_pos.size(); i++){
            cout << "(" << put_pos[i].x << " " << put_pos[i].y << ")";
        }
        cout << endl;*/
        if (complete()) {
            if (depth < ans)
                ans = depth;
        }

        //put_pos.pop_back();
        board[current_ladder.y][current_ladder.x] = false;
        current_ladder = get_next_ladder(current_ladder);

    }

    if (depth == 3) return;

    current_ladder = get_next_ladder(prev_ladder);
    while (!(current_ladder.y == 1 && current_ladder.x == N)) {

        board[current_ladder.y][current_ladder.x] = true;
        //put_pos.push_back({current_ladder.x, current_ladder.y});
        rec(depth + 1, current_ladder);
        //put_pos.pop_back();
        board[current_ladder.y][current_ladder.x] = false;
        current_ladder = get_next_ladder(current_ladder);

    }


}

int main() {

    cin >> N >> M >> H;

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> y >> x;
        board[y][x] = true;
    }


    if (complete())
        ans = 0;
    else
        rec(1, {1, 0});


    if (ans == 4)
        cout << "-1";
    else
        cout << ans;


    return 0;
}