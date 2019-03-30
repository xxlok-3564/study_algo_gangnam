#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct node {
    vector<bool> loc;

    int team_num;   // 0 없는거, 1 대문자 팀, 2 소문자 팀
    int node_num;
    int x;
    int y;

    int next_node;
    int short_cut = -1;
};

int get_forward(string command) {

    int ans = 0;
    for (int i = 0; i < 4; i++)
        if (command[i] == 'F')
            ans += 1;

    if (ans == 0)
        ans = 5;

    return ans;

}

int get_team(char a) {
    if ('a' <= a && a <= 'z')
        return 0;
    else
        return 1;
}

void init_board(node board[29]) {

    //short_cut 정리
    (board + 5)->short_cut = 20;
    (board + 10)->short_cut = 25;
    (board + 22)->short_cut = 27;

    //next
    for (int i = 0; i < 19; i++)
        (board + i)->next_node = i + 1;

    (board + 19)->next_node = 0;

}

int main() {

    string display;
    display = "..----..----..----..----..----..\n"
              "..    ..    ..    ..    ..    ..\n"
              "| \\                          / |\n"
              "|  \\                        /  |\n"
              "|   \\                      /   |\n"
              "|    ..                  ..    |\n"
              "..   ..                  ..   ..\n"
              "..     \\                /     ..\n"
              "|       \\              /       |\n"
              "|        \\            /        |\n"
              "|         ..        ..         |\n"
              "|         ..        ..         |\n"
              "..          \\      /          ..\n"
              "..           \\    /           ..\n"
              "|             \\  /             |\n"
              "|              ..              |\n"
              "|              ..              |\n"
              "|             /  \\             |\n"
              "..           /    \\           ..\n"
              "..          /      \\          ..\n"
              "|         ..        ..         |\n"
              "|         ..        ..         |\n"
              "|        /            \\        |\n"
              "|       /              \\       |\n"
              "..     /                \\     ..\n"
              "..   ..                  ..   ..\n"
              "|    ..                  ..    |\n"
              "|   /                      \\   |\n"
              "|  /                        \\  |\n"
              "| /                          \\ |\n"
              "..    ..    ..    ..    ..    ..\n"
              "..----..----..----..----..----..";


    int N;
    cin >> N;

    node board[29];

    init_board(board);

    int teamA[4];  // -1은 출발점
    int teamB[4];  // -2는 끝난 거

    char piece;
    string command;
    for (int i = 0; i < N; i++) {
        cin >> piece >> command;
        int forward = get_forward(command);
        int team = get_team(piece); //0은 소문자팀, 1은 대문자 팀팀

        if (team == 0) {


        } else {

        }

    }


    return 0;
}