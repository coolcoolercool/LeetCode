// Created by rainyzwzhou on 2022/6/5.

/**
题目描述:

核心思想:
**/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	mt19937 gen{random_device{}()};
	uniform_real_distribution<double> dis;
	double xc, yc, rLen;

public:
	Solution(double radius, double x_center, double y_center) : dis(-radius, radius), xc(x_center), yc(y_center),
	                                                            rLen(radius) {}

	vector<double> randPoint() {
		while (true) {
			double curX = dis(gen), curY = dis(gen);
			if (curX * curX + curY * curY <= rLen * rLen) {
				return {xc + curX, yc + curY};
			}
		}
	}
};
