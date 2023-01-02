// Created by 周子望 on 2022/12/11.

/**
题目描述:

核心思想:
预期是想让数据严格递增，方式只能增加1，因此这里每次比较当前元素与前一个元素，如果比前一个元素大，则记录下一个元素至少是当前元素加1;
如果当前元素比之前元素加1小，则当前元素预期是前一个元素+1. 由此计算需要加1的次数

**/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minOperations(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) {
			return 0;
		}

		int res = 0, preNum = nums[0];
		for(int i = 1; i < size; i++) {
			if (nums[i] < preNum + 1) {
				res += preNum + 1 - nums[i];
				preNum = preNum + 1;
			} else {
				preNum = nums[i];
			}
		}

		return res;
	}
};