// Created by rainyzwzhou on 2022/5/11.

/**
 * 核心思想:
 * https://leetcode.cn/problems/house-robber/solution/da-jia-jie-she-by-leetcode-solution/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		} else if (nums.size() == 2) {
			return max(nums[0], nums[1]);
		}

		vector<int> dp(nums.size());  // dp[i]表示，去i家偷，目前最大金额数量
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);

		for(int i = 2; i < nums.size(); i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}

		return dp[nums.size() - 1];
	}

	// 最开始的思维，使用一个vector<2, vector<int>(nums.size())> 二维DP数组
	// dp[i][0]表示打劫第i间房所能获得的最大金额，dp[i][1] 表示不打劫第i间房所能获得的最大金额
	int rob_000(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		} else if (nums.size() == 2) {
			return max(nums[0], nums[1]);
		}

		vector<vector<int>> dp(2, vector<int>(nums.size())); // dp[i][0]表示打劫第i间房所能获得的最大金额，dp[i][1] 表示不打劫第i间房所能获得的最大金额
		dp[0][0] = nums[0];
		dp[0][1] = 0;

		for(int i = 1; i < nums.size(); i++) {
			dp[i][0] = dp[i - 1][1] + nums[i];
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
		}

		return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
	}


	// 使用一维数组来保存结果
	// dp[i]表示，偷i家，和不偷i家的目前的最大金额
	// dp[i] = max(dp[i - 2]+nums[i], dp[i - 1])
	int rob_001(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		} else if (nums.size() == 2) {
			return max(nums[0], nums[1]);
		}

		vector<int> dp(nums.size());  // dp[i]表示，去i家偷，目前最大金额数量
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);

		for(int i = 2; i < nums.size(); i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}

		return dp[nums.size() - 1];
	}

	// 考虑到每间房屋的最高总金额只和该房屋的前两间房屋的最高总金额相关，因此可以使用滚动数组，在每个时刻只需要存储前两间房屋的最高总金额
	int rob_002(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		} else if (nums.size() == 2) {
			return max(nums[0], nums[1]);
		}

		int size = nums.size();
		if (size == 1) {
			return nums[0];
		}
		int curNoMax = nums[0], curYesMax = max(nums[0], nums[1]);
		for (int i = 2; i < size; i++) {
			int temp = curYesMax;
			curYesMax = max(curNoMax + nums[i], curYesMax);
			curNoMax = temp;
		}
		return curYesMax;
	}

	// 自己更喜欢这版
	int rob_003(vector<int> &nums) {
		int curYesMax = nums[0], curNoMax = 0;
		int size = nums.size();
		for (int i = 1; i < size; i++) {
			int preNoMax = curNoMax;
			int preYesMax = curYesMax;
			curNoMax = max(preYesMax, preNoMax);
			curYesMax = preNoMax + nums[i];
		}

		return max(curNoMax, curYesMax);
	}
};

