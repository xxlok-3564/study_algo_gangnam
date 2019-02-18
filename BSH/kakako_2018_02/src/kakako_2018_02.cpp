//============================================================================
// Name        : kakako_2017_02.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<double, int> a, pair<double, int> b) {

	if (a.first > b.first)
		return true;
	else if (a.first == b.first) {
		if (a.second < b.second)
			return true;
	}

	return false;

}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	vector<int> arr(N + 2, 0);
	vector<int> sum(N + 2, 0);
	vector<pair<double, int> > stage_fail;

	for (int i = 0; i < (int) stages.size(); i++)
		arr[stages[i]] += 1;

	sum[N + 1] = arr[N + 1];

	for (int i = N; i > 0; i--)
		sum[i] = arr[i] + sum[i + 1];

	for (int i = 1; i <= N; i++)
		if (sum[i] == 0)
			stage_fail.push_back( { 0, i });
		else
			stage_fail.push_back( { (double) arr[i] / (double) sum[i], i });

	sort(stage_fail.begin(), stage_fail.end(), comp);

	for (int i = 0; i < (int) stage_fail.size(); i++)
		answer.push_back(stage_fail[i].second);

	return answer;
}

int main() {

	vector<int> arr = { 4, 4, 4, 4, 4 };

	vector<int> ans = solution(4, arr);

	return 0;
}
