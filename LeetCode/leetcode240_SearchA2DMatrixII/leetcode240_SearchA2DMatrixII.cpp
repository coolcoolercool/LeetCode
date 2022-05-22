// Created by rainyzwzhou on 2022/5/12.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size(), cols = matrix[0].size();
		int curX = 0, curY = cols - 1;

		while(curX < rows && curY >= 0) {
			if(matrix[curX][curY] == target) {
				return true;
			} else if (matrix[curX][curY] < target) {
				curX++;
			} else {
				curY--;
			}
		}

		return false;
	}
};