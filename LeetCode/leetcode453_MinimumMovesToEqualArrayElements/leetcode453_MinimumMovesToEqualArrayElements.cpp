// Created by 周子望 on 2022/10/23.
#include "../../include.h"
/**
题目描述:

核心思想:
https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/solutions/1054870/zui-xiao-cao-zuo-ci-shu-shi-shu-zu-yuan-3meg3/

反过来想，不增加 size - 1，而是单独减少一个数字

**/

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int minNum = *min_element(nums.begin(), nums.end());
		int res = 0;
		for(int num: nums) {
			res += num - minNum;
		}
		return res;
	}
};