// Created by 周子望 on 2022/10/16.
#include "../../include.h"

/**
题目描述:
给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
https://leetcode.cn/problems/maximum-product-of-three-numbers/

核心思想:
如果数组中全是非负数，则排序后最大的三个数相乘即为最大乘积；如果全是非正数，则最大的三个数相乘同样也为最大乘积。
如果数组中有正数有负数，则最大乘积既可能是三个最大正数的乘积，也可能是两个最小负数（即绝对值最大）与最大正数的乘积。
实际上只要求出数组中最大的三个数以及最小的两个数，因此我们可以不用排序，用线性扫描直接得出这五个数
**/

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		// 最小的和第二小的
		int min1 = INT_MAX, min2 = INT_MAX;
		// 最大的、第二大和第三大的
		int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

		for(int num: nums) {
			if (num < min1) {
				min2 = min1;
				min1 = num;
			} else if (num < min2) {
				min2 = num;
			}

			if (num > max1) {
				max3 = max2;
				max2 = max1;
				max1 = num;
			} else if (num > max2) {
				max3 = max2;
				max2 = num;
			} else if (num > max3) {
				max3 = num;
			}
		}

		return max(min1 * min2 * max1, max1 * max2 * max3);
	}

	// 三重循环会有超时用例
	int maximumProduct_ver0(vector<int>& nums) {
		int result = -1000 * -1000 * -1000 - 1, size = nums.size();
		for(int i = 0; i < size; i++) {
			for(int j = i + 1; j < size; j++) {
				for(int k = j + 1; k < size; k++) {
					result = max(result, nums[i] * nums[j] * nums[k]);
				}
			}
		}

		return result;
	}
};