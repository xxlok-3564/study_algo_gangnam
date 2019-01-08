//============================================================================
// Name        : 1004.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct coor{
	int x;
	int y;
};

int get_distance(coor a, coor b){
	int diff_x = a.x - b.x;
	int diff_y = a.y - b.y;

	return diff_x * diff_x + diff_y * diff_y;
}

bool circle_contain_point(coor a, coor b, int radius){
	if (get_distance(a, b) < (radius * radius))
		return true;
	return false;
}

int main() {

	int ans = 0;
	int T;
	cin >> T;

	coor start;
	coor destination;
	int num_planet;

	coor planet_position;
	int radius;

	for (int test_num = 0; test_num < T; test_num++){

		cin >> start.x >> start.y >> destination.x >> destination.y;
		cin >> num_planet;
		ans = 0;

		for(int planet = 0; planet < num_planet; planet++){

			cin >> planet_position.x >> planet_position.y >> radius;

			if(circle_contain_point(start, planet_position, radius) ^ circle_contain_point(destination, planet_position, radius))
				ans += 1;

		}
		cout << ans << endl;
	}

	return 0;
}
