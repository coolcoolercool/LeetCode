// Created by 周子望 on 2022/9/18.

/**
题目描述:

可以在这里尝试排序算法是否正确
https://leetcode.cn/problems/sort-an-array/

核心思想:


**/
#include "../../include.h"

class Solution {
public:
	int partition(vector<int>& nums, int left, int right) {
		int temp = rand() % (right - left) + left;
		swap(nums[temp], nums[left]);

		int pivot = left;
		int index = left + 1;
		for(int i = index; i <= right; i++) {
			if(nums[pivot] > nums[i]) {
				swap(nums[i], nums[index]);
				index++;
			}
		}
		swap(nums[index - 1], nums[pivot]);
		return index - 1;
	}

	void quickSort(vector<int>& nums, int left, int right) {
		if(left < right) {
			int partitionIndex = partition(nums, left, right);
			quickSort(nums, left, partitionIndex - 1);
			quickSort(nums, partitionIndex + 1, right);
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		quickSort(nums, 0, nums.size() - 1);
		return nums;
	}
};