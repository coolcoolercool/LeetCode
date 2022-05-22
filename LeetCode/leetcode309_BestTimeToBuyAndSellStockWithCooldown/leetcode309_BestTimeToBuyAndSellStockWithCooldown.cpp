// Created by rainyzwzhou on 2022/5/13.

#include <bits/stdc++.h>
using namespace std;


class Solution {
	/**
	 * 核心思想:
	 * 状态定义还是按照最熟悉的套路
		dp[i][0]:当天不持有股票能获得的最大收益
		dp[i][1]:当天持有股票能获得的最大收益
		关键在于 dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])，、
	 	这里通过dp[i-2][0]-prices[i]，表示其只能隔天买股票
	 */
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();

		if (size == 1) return 0;
		vector<vector<int>> dp(size, vector<int>(2));  // 注意这里的 row和col

		dp[0][1] = -prices[0];  // 第一天持有股票
		dp[1][0] = max(0, dp[0][1] + prices[1]);  // 第二天不持有股票
		dp[1][1] = max(dp[0][1], -prices[1]);  // 第二天持有股票
		for (int i = 2; i < size; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); // 第 i 天，不持有股票的最大收益
			dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]); // 第 i 天，持有股票的最大收益
		}
		return dp[size - 1][0];
	}
};