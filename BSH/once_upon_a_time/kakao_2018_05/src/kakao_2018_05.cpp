//============================================================================
// Name        : kakao_2018_05.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<vector<int>, int> info_to_num;

bool cmp(const vector<int> &a, const vector<int> &b) {

	if (a[1] > b[1])
		return true;
	else if (a[1] == b[1])
		if (a[0] < b[0])
			return true;

	return false;

}

void pre(int left_boundary, int right_boundary, vector<vector<int> > &nodeinfo,
		vector<int> &pre_set) {

	sort(nodeinfo.begin(), nodeinfo.end(), cmp);

	vector<int> root = nodeinfo[0];
	pre_set.push_back(info_to_num[root]);

	vector<vector<int> > left_set;
	vector<vector<int> > right_set;

	for (int i = 1; i < nodeinfo.size(); i++) {
		if (left_boundary <= nodeinfo[i][0] && nodeinfo[i][0] < root[0])
			left_set.push_back(nodeinfo[i]);
		else
			right_set.push_back(nodeinfo[i]);
	}

	if (left_set.size() > 0)
		pre(left_boundary, root[0], left_set, pre_set);

	if (right_set.size() > 0)
		pre(root[0] + 1, right_boundary, right_set, pre_set);

}

void post(int left_boundary, int right_boundary, vector<vector<int> > &nodeinfo,
		vector<int> &post_set) {

	sort(nodeinfo.begin(), nodeinfo.end(), cmp);

	vector<int> root = nodeinfo[0];

	vector<vector<int> > left_set;
	vector<vector<int> > right_set;

	for (int i = 1; i < nodeinfo.size(); i++) {
		if (left_boundary <= nodeinfo[i][0] && nodeinfo[i][0] < root[0])
			left_set.push_back(nodeinfo[i]);
		else
			right_set.push_back(nodeinfo[i]);
	}

	if (left_set.size() > 0)
		post(left_boundary, root[0], left_set, post_set);

	if (right_set.size() > 0)
		post(root[0] + 1, right_boundary, right_set, post_set);

	post_set.push_back(info_to_num[root]);

}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	vector<int> pre_set;
	vector<int> post_set;

	for (int i = 0; i < nodeinfo.size(); i++)
		info_to_num.insert( { nodeinfo[i], i + 1 });

	pre(0, 100000, nodeinfo, pre_set);
	post(0, 100000, nodeinfo, post_set);
	answer.push_back(pre_set);
	answer.push_back(post_set);

	return answer;
}

int main() {

	vector<vector<int>> nodeinfo = { { 5, 3 }, { 11, 5 }, { 13, 3 }, { 3, 5 }, {
			6, 1 }, { 1, 3 }, { 8, 6 }, { 7, 2 }, { 2, 2 } };

	solution(nodeinfo);

	return 0;
}
