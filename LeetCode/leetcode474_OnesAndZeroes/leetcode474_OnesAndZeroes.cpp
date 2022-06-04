// Created by rainyzwzhou on 2022/5/23.

/**
题目描述:
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

核心思想:
https://leetcode.cn/problems/ones-and-zeroes/solution/yi-he-ling-by-leetcode-solution-u2z2/

经典的背包问题可以使用二维动态规划求解，两个维度分别是物品和容量。这道题有两种容量，因此需要使用三维动态规划求解，三个维度分别是字符串、0 的容量和 1 的容量。
定义三维数组 dp，其中 dp[i][j][k] 表示在前 i 个字符串中，使用 j 个 0 和 k 个 1 的情况下最多可以得到的字符串数量。假设数组 str 的长度为 l，则最终答案为 dp[l][m][n]。
初始化：为了避免分类讨论，通常多设置一行。这里可以认为，第 0 个字符串是空串。第 0 行默认初始化为 0。

**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countZero(string &str) {
		int zeroCnt = 0;
		for (auto e : str) {
			if (e == '0') zeroCnt++;
		}
		return zeroCnt;
	}

	int findMaxForm(vector<string> &strs, int m, int n) {
		int size = strs.size();

		vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(
				n + 1)));  // 定义状态：尝试题目问啥，就把啥定义成状态。dp[i][j][k] 表示输入字符串在子区间 [0, i] 能够使用 j 个 0 和 k 个 1 的字符串的最大数量

		// 初始化：为了避免分类讨论，通常多设置一行。这里可以认为，第 0 个字符串是空串。第 0 行默认初始化为 0。

		for (int i = 1; i <= size; i++) {
			int zero = countZero(strs[i - 1]); // 注意这里有一位偏移
			int one = strs[i - 1].size() - zero;

			for (int j = 0; j <= m; j++) {
				for (int k = 0; k <= n; k++) {
					if (j >= zero && k >= one) {
						dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zero][k - one] +
						                                   1); // 选择当前字符串，dp[i−1][j−当前字符串使用0的个数][k−当前字符串使用1的个数]+1
					} else {
						dp[i][j][k] = dp[i - 1][j][k]; // 不选择当前考虑的字符串，至少是这个数值
					}
				}
			}
		}

		return dp[size][m][n];
	}
};
