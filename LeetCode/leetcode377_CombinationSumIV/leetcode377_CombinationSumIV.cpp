// Created by rainyzwzhou on 2022/6/4.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/combination-sum-iv/solution/shu-ju-jie-gou-he-suan-fa-dong-tai-gui-h-jain/

https://leetcode.cn/problems/combination-sum-iv/solution/gong-shui-san-xie-yu-wan-quan-bei-bao-we-x0kn/
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	// https://leetcode.cn/problems/combination-sum-iv/solution/shu-ju-jie-gou-he-suan-fa-dong-tai-gui-h-jain/
public:
	int combinationSum4(vector<int> &nums, int target) {
		vector<int> f(target + 1, 0); // or vector<unsigned long long> f(target + 1,0); 就不用做取模的操作了
		f[0] = 1;
		for (int i = 1; i <= target; i++) {
			for (auto num : nums) {
				//c++计算的中间结果会溢出，但因为最终结果是int
				//因此每次计算完都对INT_MAX取模，0LL是将计算结果提升到long long类型
				if (i >= num) f[i] = (0LL + f[i] + f[i - num]) % INT_MAX;
			}
		}
		return f[target];
	}
};

class Solution_DiGui {
public:
	// 回溯 + 备忘录 记忆搜索
	unordered_map<int, int> mp;

	int combinationSum4(vector<int> &nums, int target) {
		unordered_map<int, int> mp;
		return helper(nums, target, mp);
	}

	int helper(vector<int> &nums, int remain, unordered_map<int, int> &mp) {
		if (remain == 0)
			return 1;
		if (remain < 0)
			return 0;
		if (mp.count(remain) != 0)
			return mp[remain];
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			res += helper(nums, remain - nums[i], mp);
		}
		mp[remain] = res;
		return res;
	}
};

