// Created by 周子望 on 2022/12/4.

/**
题目描述:

核心思想:
**/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) {
			return false;
		}
		int rows = matrix.size(), cols = matrix[0].size();
		int curX = 0, curY = cols - 1;
		while(curX < rows && curY >= 0) {
			if (matrix[curX][curY] > target) {
				curY--;
			} else if(matrix[curX][curY] < target) {
				curX++;
			} else {
				return true;
			}
		}
		return false;
	}
};