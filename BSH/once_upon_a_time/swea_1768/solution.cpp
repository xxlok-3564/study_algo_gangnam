//
// Created by bsh on 19. 3. 27.
//

#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#define N 4

using namespace std;

typedef struct {
    int strike;
    int ball;
} Result;

extern Result query(int guess[]);

void doUserImplementation(int guess[]) {


    while (1) {

        // 쿼리 보낼 숫자 선택
        int temp[4];

        Result temp_result = query(temp);

        if (temp_result.strike == 4) {
            for(int i = 0; i < 4; i++) guess[i] = temp[i];
            break;
        } else if (temp_result.strike == 3) {

        } else if (temp_result.strike == 2 && temp_result.ball == 2) {

        } else if (temp_result.strike == 2 && temp_result.ball == 1) {

        } else if (temp_result.strike == 2 && temp_result.ball == 0) {

        } else if (temp_result.strike == 1 && temp_result.ball == 3) {

        } else if (temp_result.strike == 1 && temp_result.ball == 2) {

        } else if (temp_result.strike == 1 && temp_result.ball == 1) {

        } else if (temp_result.strike == 1 && temp_result.ball == 0) {

        } else if (temp_result.strike == 0 && temp_result.ball == 4) {

        } else if (temp_result.strike == 0 && temp_result.ball == 3) {

        } else if (temp_result.strike == 0 && temp_result.ball == 2) {

        } else if (temp_result.strike == 0 && temp_result.ball == 1) {

        } else if (temp_result.strike == 0 && temp_result.ball == 0) {


        }


    }


}