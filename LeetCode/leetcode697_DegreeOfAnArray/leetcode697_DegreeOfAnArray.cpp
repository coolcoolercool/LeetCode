// Created by rainyzwzhou on 2022/5/22.

/**
题目描述:
给定一个非空且只包含非负数的整数数组nums，数组的 度 的定义是指数组里任一元素出现频数的最大值。
你的任务是在 nums 中找到与nums拥有相同大小的度的最短连续子数组，返回其长度。

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, vector<int>> mp;
		int maxCount = 0;
		for(int i = 0; i < nums.size(); i++) {
			mp[nums[i]].push_back(i);
			maxCount = max(maxCount, (int)mp[nums[i]].size());
		}
		if(maxCount == 1) return 1;

		// maxCount > 1
		int res = nums.size() + 1;
		for(auto& elem : mp) {
			if(elem.second.size() == maxCount) {
				res = min(res, elem.second[maxCount - 1] - elem.second[0] + 1);
			}
		}

		return res;
	}
};