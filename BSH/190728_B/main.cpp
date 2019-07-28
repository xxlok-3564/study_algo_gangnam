#include <iostream>

#define ADDUSER 0
#define ADDMOVIE 1
#define WATCHMOVIE 2
#define RECOMMANDMOVIE 3

using namespace std;

extern void init();

extern void addUser(int uid);

extern void addMovie(int mid);

extern void watchMovie(int uid, int mid);

extern int recommandMovie(int uid);

int main() {

    ios::sync_with_stdio(false);

    freopen("./input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {

        init();

        int total_commands;
        cin >> total_commands;

        for (int i = 0; i < total_commands; i++) {

            int uid, mid;
            int command;
            cin >> command;

            switch (command) {
                case ADDUSER:
                    cin >> uid;
                    addUser(uid);
                    break;
                case ADDMOVIE:
                    cin >> mid;
                    addMovie(mid);
                    break;

                case WATCHMOVIE:
                    cin >> uid >> mid;
                    watchMovie(uid, mid);
                    break;

                case RECOMMANDMOVIE:
                    cin >> uid;
                    cout << recommandMovie(uid) << '\n';
                    break;
            }
        }
    }


    return 0;
}