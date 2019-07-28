#include <iostream>
#include <vector>

using namespace std;

#define MAX_VAL 1000000000

int main() {

    while (true) {

        vector<string> command_list;
        string command;
        bool quit_flag = false;

        while (1) {

            getline(cin, command);

            if ("END" == command)
                break;
            if ("QUIT" == command) {
                quit_flag = true;
                break;
            }

            command_list.push_back(command);

        }

        if (quit_flag)
            break;

        int num;
        bool success = true;
        vector<long long> stk(1000);
        int last_idx = 0;
        cin >> num;

        for (int i = 0; i < num; i++) {

            int init_number;
            cin >> init_number;
            stk[last_idx] = init_number;
            last_idx += 1;

            for (string &cmd: command_list) {
                if ("POP" == cmd) {
                    cmd.substr(0, 3);
                }
            }

        }

        //엔터키 처리할 필요 확인
        getline(cin, command);

        getline(cin, command);

    }


    return 0;
}