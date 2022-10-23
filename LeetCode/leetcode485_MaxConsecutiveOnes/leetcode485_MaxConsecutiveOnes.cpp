// Created by 周子望 on 2022/10/16.
#include "../../include.h"

/**
题目描述:
给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。

核心思想:
**/


class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int result = 0, count = 0;
		for(int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				count++;
			} else {
				result = max(count, result);
				count = 0;
			}
		}
		result = max(count, result);
		return result;
	}

	int findMaxConsecutiveOnes_ziji(vector<int>& nums) {
		int size = nums.size();
		int start = -1, result = 0;
		for(int i = 0; i < size; i++) {
			if (nums[i] == 1) {
				start = i;
				while(start + 1 < size && nums[start + 1] == 1) {
					start++;
				}
				result = max(result, start - i + 1);
				i = start;
			}
		}
		return result;
	}


};



