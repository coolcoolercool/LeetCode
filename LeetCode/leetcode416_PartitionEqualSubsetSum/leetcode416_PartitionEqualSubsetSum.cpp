// Created by rainyzwzhou on 2022/5/13.

/**
题目描述:

核心思想:
 https://leetcode.cn/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/

 作为「0-1 背包问题」，它的特点是：「每个数只能用一次」。解决的基本思路是：物品一个一个选，容量也一点一点增加去考虑，这一点是「动态规划」的思想，特别重要。
在实际生活中，我们也是这样做的，一个一个地尝试把候选物品放入「背包」，通过比较得出一个物品要不要拿走。

具体做法是：画一个 len 行，target + 1 列的表格。这里 len 是物品的个数，target 是背包的容量。len 行表示一个一个物品考虑，target + 1多出来的那 1 列，表示背包容量从 0 开始考虑。很多时候，我们需要考虑这个容量为 0 的数值。

状态与状态转移方程
状态定义：dp[i][j]表示从数组的 [0, i] 这个子区间内挑选一些正整数，每个数只能用一次，使得这些数的和恰好等于 j。
状态转移方程：很多时候，状态转移方程思考的角度是「分类讨论」，对于「0-1 背包问题」而言就是「当前考虑到的数字选与不选」。

（1）不选择 nums[i]，如果在 [0, i - 1] 这个子区间内已经有一部分元素，使得它们的和为 j ，那么 dp[i][j] = true；
（2）选择 nums[i]，如果在 [0, i - 1] 这个子区间内就得找到一部分元素，使得它们的和为 j - nums[i]。
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	// dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0 个），是否存在一种选取方案使得被选取的正整数的和等于 j
public:
	bool canPartition(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) {
			return false;
		}
		int sum = 0, maxNum = 0;
		for(auto element : nums) {
			maxNum = max(maxNum, element);
			sum += element;
		}

		if (sum & 1)  return false;
		int target = sum / 2;
		if (maxNum > target)  return false;

		vector<vector<bool>> dp(size, vector<bool>(target + 1, false));
		// 初始化，当 j和为0，都是为true，因为可以都不取
		for (int i = 0; i < size; i++) {
			dp[i][0] = true;
		}

		// 初始化，这里其实是每个数值单独取的时候，可以达到的 和 的情况
		for(int i = 0; i < nums.size(); i++) {
			dp[i][nums[i]] = true;
		}

		for (int i = 1; i < size; i++) {  // 对于 nums[i]的物品是否选择
			int num = nums[i];
			for (int j = 1; j <= target; j++) {
				if (j >= num) {
					// 选择 nums[i]，如果在 [0, i - 1] 这个子区间内就得找到一部分元素，使得它们的和为 j - nums[i]
					dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
				} else {
					// 选择 nums[i]，如果在 [0, i - 1] 这个子区间内就得找到一部分元素，使得它们的和为 j - nums[i]。
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[size - 1][target];
	}









	bool canPartition_print(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) {
			return false;
		}
		int sum = 0, maxNum = 0;
		for(auto element : nums) {
			maxNum = max(maxNum, element);
			sum += element;
		}

		if (sum & 1)  return false;
		int target = sum / 2;
		if (maxNum > target)  return false;

		vector<vector<bool>> dp(size, vector<bool>(target + 1, false));
		//print_vector_vector(dp);
		// 初始化，当 j和为0，都是为true，因为可以都不取
		for (int i = 0; i < size; i++) {
			dp[i][0] = true;
		}
		//print_vector_vector(dp);

		dp[0][nums[0]] = true;
		//print_vector_vector(dp);
		for (int i = 1; i < size; i++) {
			int curIndex = nums[i];
			for (int j = 1; j <= target; j++) {
				if (j >= curIndex) {
					dp[i][j] = dp[i - 1][j] | dp[i - 1][j - curIndex];
				} else {
					dp[i][j] = dp[i - 1][j];
				}
				//print_vector_vector(dp);
			}
		}

		return dp[size - 1][target];
	}
};

