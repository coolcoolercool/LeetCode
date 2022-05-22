// Created by rainyzwzhou on 2022/5/11.

/**
 * 题目描述;
 *
 * 核心思想:
 * https://leetcode.cn/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode-solution/
dp(i,j) 表示以 (i, j)为右下角，且只包含 1 的正方形的边长最大值。如果我们能计算出所有dp(i,j) 的值，那么其中的最大值即为矩阵中只包含 1 的正方形的边长最大值，其平方即为最大正方形的面积。

dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
	// dp(i,j) 表示以 (i, j)为右下角，且只包含 1 的正方形的边长最大值。如果我们能计算出所有dp(i,j) 的值，那么其中的最大值即为矩阵中只包含 1 的正方形的边长最大值，其平方即为最大正方形的面积。
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		int maxSide = 0;
		int rows = matrix.size(), cols = matrix[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] == '1') {
					if (i == 0 || j == 0) { // 这里算是初始化，但是需要更新maxSide
						dp[i][j] = 1;
					} else {
						dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					}
					maxSide = max(maxSide, dp[i][j]);
				}
			}
		}
		int res = maxSide * maxSide;
		return res;
	}


	/**
	 暴力法
	由于正方形的面积等于边长的平方，因此要找到最大正方形的面积，首先需要找到最大正方形的边长，然后计算最大边长的平方即可。

	暴力法是最简单直观的做法，具体做法如下：
	遍历矩阵中的每个元素，每次遇到 1，则将该元素作为正方形的左上角；
	确定正方形的左上角后，根据左上角所在的行和列计算可能的最大正方形的边长（正方形的范围不能超出矩阵的行数和列数），在该边长范围内寻找只包含 1 的最大正方形；
	每次在下方新增一行以及在右方新增一列，判断新增的行和列是否满足所有元素都是 1。
	 */
public:
	int maximalSquare_1(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return 0;
		}
		int maxSide = 0;
		int rows = matrix.size(), columns = matrix[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (matrix[i][j] == '1') {
					// 遇到一个 1 作为正方形的左上角
					maxSide = max(maxSide, 1);
					// 计算可能的最大正方形边长
					int currentMaxSide = min(rows - i, columns - j);
					for (int moveStep = 1; moveStep < currentMaxSide; moveStep++) {
						// 判断新增的一行一列是否均为 1
						bool flag = true;
						if (matrix[i + moveStep][j + moveStep] == '0') {
							break;
						}
						for (int m = 0; m < moveStep; m++) {
							if (matrix[i + moveStep][j + m] == '0' || matrix[i + m][j + moveStep] == '0') {
								flag = false;
								break;
							}
						}
						if (flag) {
							maxSide = max(maxSide, moveStep + 1);
						} else {
							break;
						}
					}
				}
			}
		}
		int maxSquare = maxSide * maxSide;
		return maxSquare;
	}
};

