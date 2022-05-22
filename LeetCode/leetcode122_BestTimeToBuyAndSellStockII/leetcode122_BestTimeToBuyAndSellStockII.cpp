// Created by rainyzwzhou on 2022/5/2.

/**
 题目: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

#include "../../include.h"

class Solution {
	// 定义状态 dp[i][0] 表示第 i 天交易完后手里没有股票的最大利润，dp[i][1] 表示第 i 天交易完后手里持有一支股票的最大利润（i 从 0 开始）
	// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode-s/

public:
	int maxProfit(vector<int> &prices) {
		int n = prices.size();
		int dp[n][2];
		dp[0][0] = 0, dp[0][1] = -prices[0];
		for (int i = 1; i < n; ++i) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		return dp[n - 1][0];
	}

public:
	/**
	 因为交易次数不受限，如果可以把所有的上坡全部收集到，一定是利益最大化的
	 */
	int maxProfit_easy(vector<int>& prices) {
		if (prices.size() < 2) {
			return 0;
		}

		int res = 0;
		for(int i = 1; i < prices.size(); i++) {
			if(prices[i] > prices[i - 1]) {
				res += prices[i] - prices[i - 1];
			}
		}

		return res;
	}


};
