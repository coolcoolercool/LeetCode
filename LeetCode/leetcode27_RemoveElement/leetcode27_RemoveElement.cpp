// Created by rainyzwzhou on 2022/5/2.

/**
 题目:
 给你一个数组 nums和一个值 val，你需要 原地 移除所有数值等于val的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

1211
 */

#include "../../include.h"

class Solution {
	/*
	 * 遍历一遍数组，然后将不等于val的值，依次放到左边
	 */
public:
	int removeElement(vector<int>& nums, int val) {
		int newSize = 0;
		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] != val) {
				nums[newSize] = nums[i];
				newSize++;
			}
		}

		return newSize; // 这里返回是新数组的长度 size, 因此这里不要减一
	}
};