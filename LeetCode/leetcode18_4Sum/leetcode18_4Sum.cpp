// Created by 周子望 on 2022/12/11.

/**
题目描述:

核心思想:
**/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> quadruplets;
		if (nums.size() < 4) {
			return quadruplets;
		}
		sort(nums.begin(), nums.end());
		int size = nums.size();
		for (int i = 0; i < size - 3; i++) { // 因为要四个数， 因此这里 i 最大只能是 size - 3
			if (i > 0 && nums[i] == nums[i - 1]) {  // 重复的情况，直接下一次循环
				continue;
			}
			if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) { // 最小值已经大于 target，不存在和为target的情况
				break;
			}
			if ((long) nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) { // 最大值小于 target， 不存在和为target的情况
				continue;
			}
			for (int j = i + 1; j < size - 2; j++) {
				//  三数之和的代码部分了
				if (j > i + 1 && nums[j] == nums[j - 1]) { // 重复的情况，直接下一次循环
					continue;
				}
				if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) { // 最小值已经大于 target，不存在和为target的情况
					break;
				}
				if ((long) nums[i] + nums[j] + nums[size - 2] + nums[size - 1] < target) { // 最大值小于 target， 不存在和为target的情况
					continue;
				}
				int left = j + 1, right = size - 1;
				while (left < right) {
					long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
						left++, right--;
						while (left < right && nums[left] == nums[left - 1]) {
							left++;
						}
						while (left < right && nums[right] == nums[right + 1]) {
							right--;
						}
					} else if (sum < target) {
						left++;
					} else {
						right--;
					}
				}
			}
		}
		return quadruplets;
	}
};


