// Created by rainyzwzhou on 2022/5/23.

/**
题目描述:
给定一个三角形 triangle ，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。


核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int rows = triangle.size();
		vector<vector<int>> dp(rows, vector<int>(rows));
		dp[0][0] = triangle[0][0];

		for (int i = 1; i < rows; ++i) {
			dp[i][0] = dp[i - 1][0] + triangle[i][0]; // 每层的第一个元素，只有一条路 (i,0)
			for (int j = 1; j < i; ++j) { // 每次的中间元素，有 (i-1,j) 和 (i-1,j-1) 两条路
				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
			dp[i][i] = dp[i - 1][i - 1] + triangle[i][i]; // 每层的最后一个元素，只有一条路 (i-1, i-1)
		}

		int res = INT_MAX;
		for (auto element : dp[rows - 1]) res = min(res, element);

		return res;
	}

	// 扩展打印出来，下来的路径
	// 思路: 可以遍历dp数组，找到每层的dp值最小的索引
};
