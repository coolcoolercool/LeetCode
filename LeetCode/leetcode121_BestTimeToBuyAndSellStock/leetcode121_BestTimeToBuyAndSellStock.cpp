// Created by rainyzwzhou on 2022/5/2.

#include "../../include.h"


class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.empty()) {
			return 0;
		}

		int minPrice = prices[0], maxProfit = 0;
		for(int i = 0; i < prices.size(); i++) {
			maxProfit = max(maxProfit, prices[i] - minPrice);
			minPrice = min(prices[i], minPrice);
		}

		return maxProfit;
	}

public:
	int maxProfit_On(vector<int>& prices) {
		// dp[i] 在[0, i] 天之内买的股票最低价格
		vector<int> dp;
		dp[0] = prices[0];
		for(int i = 1; i < prices.size(); i++) {
			dp[i] = min(dp[i - 1], prices[i]);
		}

		int maxRes = 0;
		for(int i = 0; i < prices.size(); i++) {
			maxRes = max(prices[i] - dp[i], maxRes);
		}

		return maxRes;
	}
};