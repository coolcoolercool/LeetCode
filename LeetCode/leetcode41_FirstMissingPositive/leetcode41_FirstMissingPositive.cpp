// Created by rainyzwzhou on 2022/5/15.

/**
题目描述:
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

核心思想:
使用数组作为hash空间，将value对应的索引 mp = value - 1，对应的值置为负数，表示这个正整数出现过
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// 将元素交换到对应的位置
	int firstMissingPositive(vector<int>& nums) {
		int size = nums.size();
		for(int i = 0; i < size; i++) {
			while(nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}

		for(int i = 0; i < size; i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return size + 1;
	}

	// 使用正负号作为标记
	int firstMissingPositive_solution1(vector<int>& nums) {
		int size = nums.size();

		for (int& num: nums) {  // 排除负数 和 0 的干扰
			if (num <= 0) num = size + 1; // 注意这里是 <= 0
		}

		for (int i = 0; i < size; ++i) { // 将整数在nums对应的索引，的值置为负数
			int index = abs(nums[i]);  // 如果index = 1，则nums[0]对应的数字置为负数
			if (index <= size) nums[index - 1] = -abs(nums[index - 1]); // 这里是 index <= size
		}

		for (int i = 0; i < size; ++i) { // 此时，索引对应的值为正整数，表示这个正数缺失，第一个遇到的就是最小缺失的正数
			if (nums[i] > 0) return i + 1;
		}

		return size + 1; // 如果数组中没有缺失，那么数组中最大的正整数后的后一位为缺失的最小正整数
	}
};
