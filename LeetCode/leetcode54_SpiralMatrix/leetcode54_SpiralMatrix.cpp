// Created by rainyzwzhou on 2022/5/15.

/**
题目描述:
https://leetcode.cn/problems/spiral-matrix/
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

核心思想:
层次遍历，设置好四个变量表示上下左右

解法概括:
设立四个边界，不断移动缩小
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if(matrix.empty()) return res;

		int rows = matrix.size(), cols = matrix[0].size();
		int left = 0;
		int right = cols - 1;
		int top = 0;
		int bottom = rows - 1;
		int count = rows * cols;

		while (count >= 1) {
			for (int i = left; i <= right && count >= 1; i++) {  // left -> right， 此时的横坐标是 top
				res.push_back(matrix[top][i]);
				count--;
			}
			top++;
			for (int i = top; i <= bottom && count >= 1; i++) {  // top -> bottom，此时纵坐标是 right
				res.push_back(matrix[i][right]);
				count--;
			}
			right--;
			for (int i = right; i >= left && count >= 1; i--) { // right -> left，此时横坐标是 bottom
				res.push_back(matrix[bottom][i]);
				count--;
			}
			bottom--;
			for (int i = bottom; i >= top && count >= 1; i--) { // bottom -> top，此时纵坐标是 left
				res.push_back(matrix[i][left]);
				count--;
			}
			left++;
		}
		return res;
	}

	// 这种方法太特意化了
	vector<int> spiralOrder_0(vector<vector<int>>& matrix) {
		vector <int> ans;
		if(matrix.empty()) return ans; //若数组为空，直接返回答案

		int u = 0; //赋值上下左右边界
		int d = matrix.size() - 1;
		int l = 0;
		int r = matrix[0].size() - 1;

		while(true)
		{
			for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
			if(++ u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
			for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
			if(-- r < l) break; //重新设定有边界
			for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
			if(-- d < u) break; //重新设定下边界
			for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
			if(++ l > r) break; //重新设定左边界
		}
		return ans;
	}

};