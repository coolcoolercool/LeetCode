// Created by rainyzwzhou on 2022/6/6.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/valid-square/solution/gen-ju-zheng-fang-xing-he-ling-xing-de-ding-yi-pan/

 p1   p2

 p3   p4
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	double help(vector<int> &p1, vector<int> &p2) {
		return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (p2[0] - p1[0]); // 这里没有选择开方，为了避免开方后小数点影响判断
	}

	bool validSquare1(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
		vector<double> lenVec;
		lenVec.push_back(help(p1, p2));            //相邻的和不相邻的均进行计算  相邻的是边，不相邻的是对角线
		lenVec.push_back(help(p2, p3));
		lenVec.push_back(help(p3, p4));
		lenVec.push_back(help(p4, p1));
		lenVec.push_back(help(p1, p3));
		lenVec.push_back(help(p2, p4));

		sort(lenVec.begin(), lenVec.end());
		if (lenVec[0] == 0) {
			return false;
		} else if (lenVec[0] == lenVec[1] && lenVec[1] == lenVec[2] && lenVec[2] == lenVec[3] &&
		           lenVec[4] == lenVec[5]) // 如果是正方形，则排序后，前四条边长度相等，最后两条对角线长度相等
			return true;
		return false;
	}
};