//============================================================================
// Name        : kakao_2018_03.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
using namespace std;

// dfs X. ex) BC가 답이라 할 때 ABC가 먼저 서치

void make_order(int depth, int end, int start, int num_column,
		vector<int> &order, queue<vector<int> > &select_column) {

	if (depth > end)
		return;

	for (int i = start; i < num_column; i++) {
		order.push_back(i);

		if (depth == end) {
			select_column.push(order);
		} else {
			make_order(depth + 1, end, i + 1, num_column, order, select_column);
		}

		order.pop_back();
	}

}

int solution(vector<vector<string>> relation) {

	int num_row = relation.size();
	int num_col = relation[0].size();

	queue<vector<int> > select_column;
	vector<int> order;
	vector<bool> finish(num_col, false);
	for (int i = 1; i <= 4; i++)
		make_order(1, i, 0, num_col, order, select_column);


	while(!select_column.empty()){




		select_column.pop();
	}


}

int main() {
	vector<vector<string> > relation = { { "100", "ryan", "music", "2" }, {
			"200", "apeach", "math", "2" }, { "300", "tube", "computer", "3" },
			{ "400", "con", "computer", "4" }, { "500", "muzi", "music", "3" },
			{ "600", "apeach", "music", "2" } };

	cout << solution(relation);

	return 0;
}
