//
// Created by rainyzwzhou on 2022/5/2.
//
/**
题目:
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

 */

#include "../../include.h"


class Solution {
/**
核心思想:
异或运算有以下三个性质。
1. 任何数和 0 做异或运算，结果仍然是原来的数。
2. 任何数和其自身做异或运算，结果是 0。
3. 异或运算满足交换律和结合律。
 */

public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for(auto element : nums) {
			ret ^= element;
		}

		return ret;
	}
};