// Created by rainyzwzhou on 2022/5/24.

/**
题目描述:
https://leetcode.cn/problems/3sum-closest/
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
返回这三个数的和。
假定每组输入只存在恰好一个解。


核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int size = nums.size();
		sort(nums.begin(), nums.end());

		int closeDiff = INT_MAX;  // 记录最小差值
		int res = INT_MAX; // 记录最终的最小差值对应的 sum
		for(int i = 0; i < size; i++) {
			if(i > 0 && nums[i] == nums[i - 1]) continue;

			int left = i + 1, right = size - 1;
			while(left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				int diff = abs(sum - target); // 更新差值
				if(closeDiff > diff) { // 维护最小差值的sum
					closeDiff = diff;
					res = sum;
				}

				if(sum == target) { // 如果sum == target, 则直接返回结果，没有比这个更接近了
					return sum;
				} else if(sum > target) {
					right--;
				} else {
					left++;
				}
			}
		}

		return res;
	}
};