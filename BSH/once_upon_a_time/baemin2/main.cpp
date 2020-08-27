#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> lands, vector<vector<int>> wells, vector<int> point) {
    bool answer = true;

    for (int i = 0; i < lands.size(); i++) {
        vector<int> current_land = lands[0];
        if ((current_land[2] <= point[0]) || (point[2] <= current_land[0]) || (current_land[3] <= point[1]) ||
            (point[3] <= current_land[1]))
            answer = true;
        else
            return false;
    }

    for (int i = 0; i < wells.size(); i++) {
        vector<int> current_wells = wells[0];
        if ((point[0] <= current_wells[0]) && (current_wells[2] <= point[2]) && (point[1] <= current_wells[1]) &&
            (current_wells[3] <= point[3]))
            answer = true;
        else
            return false;
    }


    return answer;
}

int main() {

    cout << solution({{10, 0,  30, 5},
              {0,  30, 20, 50},
              {30, 30, 40, 40}},
             {{15, 15, 25, 25},
              {40, 10, 50, 20}}, {10, 10, 30, 30});


    return 0;
}