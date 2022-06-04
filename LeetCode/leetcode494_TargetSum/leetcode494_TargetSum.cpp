// Created by rainyzwzhou on 2022/6/3.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/target-sum/solution/mu-biao-he-by-nehzil-x5am/
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int> &nums, int target) {
		/* 在进行动态规划算法之前需要进行下面的判断和计算 */
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) sum += nums[i];

		int diff = sum - target;
		if (diff < 0 || diff % 2 != 0) {
			return 0;
		}
		int n = nums.size();
		int neg = diff / 2;
		/* 定义dp数组 */
		vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
		/* dp数组初始化 */
		dp[0][0] = 1;
		/* 遍历 */
		for (int i = 1; i <= n; i++) {// 先遍历物品
			for (int j = 0; j <= neg; j++) { // 在遍历背包容量
				dp[i][j] = dp[i - 1][j];
				/* 如果背包剩余j的容量大于放的物品nums[i-1]则就可以将物品nums[i-1]放入背包中 */
				if (j >= nums[i - 1]) {
					dp[i][j] += dp[i - 1][j - nums[i - 1]];
				}
			}
		}
		return dp[n][neg];
	}
};
