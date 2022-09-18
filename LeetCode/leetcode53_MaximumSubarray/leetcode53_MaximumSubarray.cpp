// Created by 周子望 on 2021/11/1.

/*
题目:
 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

核心思想:
假设 nums 数组的长度是 n，下标从 0 到 n-1。
我们用 select(i)代表以第 i 个数结尾的「连续子数组的最大和」，那么很显然我们要求的答案就是：
求出每个位置的 select(i)，然后返回 select 数组中的最大值即可。

https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/

 */

#include "../../include.h"

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res = nums[0], pre = 0;  // 注意这里 res 初始为 nums[0]
		for (const auto &element : nums) {
			pre = max(pre + element, element);
			res = max(res, pre);
		}

		return res;
	}

	// 返回 最大和的连续子数组，而不是和，返回的是子数组
	vector<int> maxSubArray_jinjie(vector<int>& nums) {
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		int maxLeft = 0, maxLen = 1;
		int curLeft = 0, curLen = 1;
		int curMax = nums[0];

		for(int i = 1; i < nums.size(); i++) {
			if(dp[i - 1] + nums[i] > nums[i]) {
				dp[i] = dp[i - 1] + nums[i];
				curLen++;
			} else {
				dp[i] = nums[i];
				curLeft = i;
				curLen = 1;
			}

			if(dp[i] > curMax) {
				maxLeft = curLeft;
				maxLen = curLen;
				curMax = dp[i];
			}
		}

		vector<int> res(nums.begin() + maxLeft, nums.begin() + maxLeft + maxLen);
		return res;
	}
};

int main_om45lmn () {
	Solution sol;
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

	int res = sol.maxSubArray(nums);

	cout << "res: " << res << endl;

	return 0;
}