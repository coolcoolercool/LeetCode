// Created by 周子望 on 2022/10/23.
#include "../../include.h"

/**
题目描述:

核心思想:
https://leetcode.cn/problems/find-all-duplicates-in-an-array/solutions/1473718/shu-zu-zhong-zhong-fu-de-shu-ju-by-leetc-782l/


**/

class Solution {
public:
	// 将元素交换到对应的位置
	vector<int> findDuplicates(vector<int>& nums) {
		int size = nums.size();
		for(int i = 0; i < size; i++) {
			if(nums[i] != i + 1) {
				while(nums[i] != nums[nums[i] - 1]) {
					swap(nums[i], nums[nums[i] - 1]);
				}
			}
		}

		vector<int> res;
		for(int i = 0; i < size; i++) {
			if (nums[i] != i + 1) {
				res.push_back(i + 1);
			}
		}

		return res;
	}

	// 使用正负号作为标记
	vector<int> findDuplicates_solution2(vector<int>& nums) {
		int size = nums.size();
		vector<int> res;
		for(int i = 0; i < size; i++) {
			int value = abs(nums[i]);
			if (nums[value - 1] > 0) {
				nums[value - 1] = -nums[value - 1];
			} else {
				res.push_back(value);
			}
		}
		return res;
	}

};