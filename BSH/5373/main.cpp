#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, char> cube;

char face[6] = {'U', 'D', 'F', 'B', 'L', 'R'};
char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
char order[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};


void U_command() {

    char temp[3];

    string a[4] = {"U1", "U7", "U5", "U3"};
    string b[4] = {"U0", "U6", "U4", "U2"};
    string c[4][3] = {{"B2", "B1", "B0"},
                      {"L2", "L1", "L0"},
                      {"F2", "F1", "F0"},
                      {"R2", "R1", "R0"}};


    temp[0] = cube[a[0]];

    for (int i = 0; i < 3; i++)
        cube[a[i]] = cube[a[i + 1]];

    cube[a[3]] = temp[0];


    temp[0] = cube[b[0]];

    for (int i = 0; i < 3; i++)
        cube[b[i]] = cube[b[i + 1]];

    cube[b[3]] = temp[0];


    for (int i = 0; i < 3; i++)
        temp[i] = cube[c[0][i]];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[c[i][j]] = cube[c[i + 1][j]];
        }
    }

    for (int i = 0; i < 3; i++)
        cube[c[3][i]] = temp[i];

}

void D_command() {

    char temp[3];

    string a[4] = {"D1", "D7", "D5", "D3"};
    string b[4] = {"D0", "D6", "D4", "D2"};
    string c[4][3] = {{"F6", "F5", "F4"},
                      {"L6", "L5", "L4"},
                      {"B6", "B5", "B4"},
                      {"R6", "R5", "R4"}};


    temp[0] = cube[a[0]];

    for (int i = 0; i < 3; i++)
        cube[a[i]] = cube[a[i + 1]];

    cube[a[3]] = temp[0];


    temp[0] = cube[b[0]];

    for (int i = 0; i < 3; i++)
        cube[b[i]] = cube[b[i + 1]];

    cube[b[3]] = temp[0];


    for (int i = 0; i < 3; i++)
        temp[i] = cube[c[0][i]];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[c[i][j]] = cube[c[i + 1][j]];
        }
    }

    for (int i = 0; i < 3; i++)
        cube[c[3][i]] = temp[i];

}

void F_command() {

    char temp[3];

    string a[4] = {"F1", "F7", "F5", "F3"};
    string b[4] = {"F0", "F6", "F4", "F2"};
    string c[4][3] = {{"U6", "U5", "U4"},
                      {"L4", "L3", "L2"},
                      {"D2", "D1", "D0"},
                      {"R0", "R7", "R6"}};


    temp[0] = cube[a[0]];

    for (int i = 0; i < 3; i++)
        cube[a[i]] = cube[a[i + 1]];

    cube[a[3]] = temp[0];


    temp[0] = cube[b[0]];

    for (int i = 0; i < 3; i++)
        cube[b[i]] = cube[b[i + 1]];

    cube[b[3]] = temp[0];


    for (int i = 0; i < 3; i++)
        temp[i] = cube[c[0][i]];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[c[i][j]] = cube[c[i + 1][j]];
        }
    }

    for (int i = 0; i < 3; i++)
        cube[c[3][i]] = temp[i];

}

void B_command() {

    char temp[3];

    string a[4] = {"B1", "B7", "B5", "B3"};
    string b[4] = {"B0", "B6", "B4", "B2"};
    string c[4][3] = {{"U2", "U1", "U0"},
                      {"R4", "R3", "R2"},
                      {"D6", "D5", "D4"},
                      {"L0", "L7", "L6"}};


    temp[0] = cube[a[0]];

    for (int i = 0; i < 3; i++)
        cube[a[i]] = cube[a[i + 1]];

    cube[a[3]] = temp[0];


    temp[0] = cube[b[0]];

    for (int i = 0; i < 3; i++)
        cube[b[i]] = cube[b[i + 1]];

    cube[b[3]] = temp[0];


    for (int i = 0; i < 3; i++)
        temp[i] = cube[c[0][i]];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[c[i][j]] = cube[c[i + 1][j]];
        }
    }

    for (int i = 0; i < 3; i++)
        cube[c[3][i]] = temp[i];

}

void R_command() {

    char temp[3];

    string a[4] = {"R1", "R7", "R5", "R3"};
    string b[4] = {"R0", "R6", "R4", "R2"};
    string c[4][3] = {{"U4", "U3", "U2"},
                      {"F4", "F3", "F2"},
                      {"D4", "D3", "D2"},
                      {"B0", "B7", "B6"}};


    temp[0] = cube[a[0]];

    for (int i = 0; i < 3; i++)
        cube[a[i]] = cube[a[i + 1]];

    cube[a[3]] = temp[0];


    temp[0] = cube[b[0]];

    for (int i = 0; i < 3; i++)
        cube[b[i]] = cube[b[i + 1]];

    cube[b[3]] = temp[0];


    for (int i = 0; i < 3; i++)
        temp[i] = cube[c[0][i]];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[c[i][j]] = cube[c[i + 1][j]];
        }
    }

    for (int i = 0; i < 3; i++)
        cube[c[3][i]] = temp[i];

}

void L_command() {

    char temp[3];

    string a[4] = {"L1", "L7", "L5", "L3"};
    string b[4] = {"L0", "L6", "L4", "L2"};
    string c[4][3] = {{"U0", "U7", "U6"},
                      {"B4", "B3", "B2"},
                      {"D0", "D7", "D6"},
                      {"F0", "F7", "F6"}};


    temp[0] = cube[a[0]];

    for (int i = 0; i < 3; i++)
        cube[a[i]] = cube[a[i + 1]];

    cube[a[3]] = temp[0];


    temp[0] = cube[b[0]];

    for (int i = 0; i < 3; i++)
        cube[b[i]] = cube[b[i + 1]];

    cube[b[3]] = temp[0];


    for (int i = 0; i < 3; i++)
        temp[i] = cube[c[0][i]];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[c[i][j]] = cube[c[i + 1][j]];
        }
    }

    for (int i = 0; i < 3; i++)
        cube[c[3][i]] = temp[i];

}

void init_cube() {

    string temp;
    temp.resize(2);

    for (int i = 0; i < 6; i++) {

        temp[0] = face[i];

        for (int j = 0; j < 8; j++) {
            temp[1] = order[j];
            cube[temp] = color[i];

        }


    }

}

void print_cube() {

    cout << cube["U0"] << cube["U1"] << cube["U2"] << '\n';
    cout << cube["U7"] << "w" << cube["U3"] << '\n';
    cout << cube["U6"] << cube["U5"] << cube["U4"] << '\n';


}

int main() {

    int test;
    int num_command;
    string command;

    cin >> test;

    for (int t = 0; t < test; t++) {

        init_cube();

        cin >> num_command;

        for (int n = 0; n < num_command; n++) {

            cin >> command;

            if (command[0] == 'U') {
                if (command[1] == '+')
                    U_command();
                else {
                    U_command();
                    U_command();
                    U_command();
                }
            } else if (command[0] == 'D') {
                if (command[1] == '+')
                    D_command();
                else {
                    D_command();
                    D_command();
                    D_command();
                }
            } else if (command[0] == 'L') {
                if (command[1] == '+')
                    L_command();
                else {
                    L_command();
                    L_command();
                    L_command();
                }
            } else if (command[0] == 'R') {
                if (command[1] == '+')
                    R_command();
                else {
                    R_command();
                    R_command();
                    R_command();
                }
            } else if (command[0] == 'F') {
                if (command[1] == '+')
                    F_command();
                else {
                    F_command();
                    F_command();
                    F_command();
                }
            } else if (command[0] == 'B') {
                if (command[1] == '+')
                    B_command();
                else {
                    B_command();
                    B_command();
                    B_command();
                }
            }

        }

        print_cube();

    }

    pair<int, int> a ={1, 2};



    return 0;
}