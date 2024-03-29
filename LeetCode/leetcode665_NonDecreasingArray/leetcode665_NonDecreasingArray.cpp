// Created by 周子望 on 2022/10/23.
#include "../../include.h"

/**
题目描述:

核心思想:
https://leetcode.cn/problems/non-decreasing-array/solutions/594975/3-zhang-dong-tu-bang-zhu-ni-li-jie-zhe-d-06gi/
**/

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int size = nums.size(), count = 0;
		for(int i = 1; i < size; i++) {
			if (nums[i] < nums[i - 1]) {
				if (i == 1 || nums[i] >= nums[i - 2]) {
					nums[i - 1] = nums[i];
				} else {
					nums[i] = nums[i - 1];
				}
				count++;
			}
		}
		return true;
	}
};