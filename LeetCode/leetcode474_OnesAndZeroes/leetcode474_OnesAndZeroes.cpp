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
	vector<int> getZerosOnes(string &str) {
		vector<int> zerosOnes(2);
		for (int i = 0; i < str.size(); i++) {
			zerosOnes[str[i] - '0']++;
		}
		return zerosOnes;
	}

	//  dp[i][j][k] 表示在前 i 个字符串中，使用 j 个 0 和 k 个 1 的情况下最多可以得到的字符串数量
	int findMaxForm(vector<string> &strs, int m, int n) { // 最多m个0和n个1
		int size = strs.size();
		vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));

		// 初始化：为了避免分类讨论，通常多设置一行。这里可以认为，第 0 个字符串是空串。第 0 行默认初始化为 0。

		for (int i = 1; i <= size; i++) {
			vector<int> zerosOnes = getZerosOnes(strs[i - 1]); // 统计0和1的个数
			int zeros = zerosOnes[0], ones = zerosOnes[1];
			for (int j = 0; j <= m; j++) {
				for (int k = 0; k <= n; k++) {
					dp[i][j][k] = dp[i - 1][j][k]; // 不选择当前考虑的字符串，至少是这个数值
					if (j >= zeros && k >= ones) {  // 选择当前字符串，dp[i−1][j−当前字符串使用0的个数][k−当前字符串使用1的个数]+1
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
					}
				}
			}
		}
		return dp[size][m][n];
	}
};
