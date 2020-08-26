#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int num_team, num_query;

    cin >> num_team >> num_query;

    unordered_map<string, int> team_name_to_idx;
    unordered_map<string, string> name_to_team;
    vector<vector<string>> board(num_team);

    for (int team = 0; team < num_team; team++) {

        string team_name;
        int num_team_member;
        cin >> team_name;
        cin >> num_team_member;

        team_name_to_idx.insert({team_name, team});

        string member;
        for (int team_member = 0; team_member < num_team_member; team_member++) {
            cin >> member;

            name_to_team.insert({member, team_name});
            board[team].push_back(member);
        }

        sort(board[team].begin(), board[team].end());

    }

    for (int query = 0; query < num_query; query++) {

        int n;
        string str;
        cin >> str >> n;

        if (n == 0) {

            for (const auto & i : board[team_name_to_idx[name_to_team[str]]])
                cout << i << '\n';

        } else if (n == 1) {

            cout << name_to_team[str] << '\n';
        }

    }


    return 0;
}