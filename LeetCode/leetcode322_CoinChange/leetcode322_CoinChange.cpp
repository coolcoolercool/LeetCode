// Created by rainyzwzhou on 2022/5/12.

/**
 * 题目描述: https://leetcode.cn/problems/coin-change/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
	/**
	 * dp[i] 表示，金额为i兑换，最少需要的硬币数
	 * dp[i] 取决于硬币值的前一个位置， 比如硬币值为coins[j]
	 * dp[i] = min(coins[i], dp[i])
	 *
	 */
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0) return 0;

		vector<int> dp(amount + 1, amount + 1);  // 初始化dp，amount理论上最多只有amount个硬币兑换，amount+1表示无法兑换
		dp[0] = 0; // 因为金额0，需要硬币数最少为0
		for (int i = 0; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				int index = i - coins[j];
				if (index >= 0) {
					dp[i] = min(dp[i], dp[index] + 1); // 注意这里加一
				}
			}
		}
		if (dp[amount] > amount) return -1;  // 表示 amount金额无法兑换 注意这种无法兑换的情况，需要返回-1

		return dp[amount];
	}
};