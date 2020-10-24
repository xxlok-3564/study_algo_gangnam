#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

void debug_fields(vector<char> &fields) {
    for (char &i : fields)
        cout << i << " ";
    cout << endl;
}

bool is_fast_player(char value, set<char> &fast_player) {
    return fast_player.find(value) != fast_player.end();
}

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames,
              int *numOfMovesPerGame) {
    // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.

    // TODO: 이후에 field 랑 score 묶어서 구조체로 변경
    vector<char> fields(numOfAllPlayers - 1);
    vector<int> current_score(numOfAllPlayers - 1, 0);
    set<char> fast_player;

    char player = 'A';
    int player_score = 1;
    int current_player_position = 0;

    // init fields
    char init_value = 'B';
    for (char &field: fields) {
        field = init_value;
        init_value += 1;
    }

    // init fast_player_list
    for (int i = 0; i < numOfQuickPlayers; i++) {
        fast_player.insert(namesOfQuickPlayers[i]);
    }

    // game logic
    for (int currentGame = 0; currentGame < numOfGames; currentGame++) {
        // 새 위치 설정,
        // current_rotate: 이번 턴 회전 방향 및 횟수
        int current_rotate = numOfMovesPerGame[currentGame];

        int new_position;
        // 만약 빠른 사람이 앉아있는 위치라면.
        if (current_rotate >= 0) {
            new_position = (current_player_position + current_rotate) % fields.size();
        } else {
            new_position = (current_player_position + current_rotate);
            if (new_position < 0)
                new_position += fields.size();
        }

        current_player_position = new_position;

        if (is_fast_player(fields[new_position], fast_player)) {
            player_score += 1;
        } else {

            swap(player, fields[new_position]);
            swap(player_score, current_score[new_position]);

            player_score += 1;
        }

    }

    for (int i = 0; i < numOfAllPlayers - 1; i++) {
        cout << fields[i] << " " << current_score[i] << endl;
    }
    cout << player << " " << player_score << endl;

}

struct input_data {
    int numOfAllPlayers;
    int numOfQuickPlayers;
    char *namesOfQuickPlayers;
    int numOfGames;
    int *numOfMovesPerGame;
};

void process_stdin(struct input_data &inputData) {
    string line;
    istringstream iss;

    getline(cin, line);
    iss.str(line);
    iss >> inputData.numOfAllPlayers;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.numOfQuickPlayers;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
    for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
        iss >> inputData.namesOfQuickPlayers[i];
    }

    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.numOfGames;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.numOfMovesPerGame = new int[inputData.numOfGames];
    for (int i = 0; i < inputData.numOfGames; i++) {
        iss >> inputData.numOfMovesPerGame[i];
    }
}

int main() {
    struct input_data inputData;
    process_stdin(inputData);

    solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers,
             inputData.numOfGames, inputData.numOfMovesPerGame);
    return 0;
}