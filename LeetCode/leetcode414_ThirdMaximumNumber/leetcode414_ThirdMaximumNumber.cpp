// Created by 周子望 on 2022/10/16.
#include "../../include.h"

/**
题目描述:

核心思想:
我们可以遍历数组，并用三个变量 aaa、bbb 和 ccc 来维护数组中的最大值、次大值和第三大值，以模拟方法二中的插入和删除操作。为方便编程实现，我们将其均初始化为小于数组最小值的元素，视作「无穷小」，比如 -2^{63} 等。

https://leetcode.cn/problems/third-maximum-number/solutions/1032401/di-san-da-de-shu-by-leetcode-solution-h3sp/
**/

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;
		for(long num : nums) {
			if (num > first) {
				third = second;
				second = first;
				first = num;
			} else if (first > num && num > second) {
				third = second;
				second = num;
			} else if (second > num && num > third){
				third = num;
			}
		}
		return third == LLONG_MIN ? first : third;
	}
};