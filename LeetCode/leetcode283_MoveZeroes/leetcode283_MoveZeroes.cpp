// Created by rainyzwzhou on 2022/5/13.


#include <bits/stdc++.h>
using namespace std;

class Solution {
	/**
	 使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。
	右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。

	注意到以下性质：
	（1）左指针左边均为非零数；
	（2）右指针左边直到左指针处均为零。

	因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变。
	 */
public:
	void moveZeroes(vector<int>& nums) {
		int size = nums.size(), left = 0, right = 0;
		while (right < size) {
			if (nums[right] != 0) { // 这里为什么right不++，因为可能left swap的元素为0,
				swap(nums[left], nums[right]);
				left++;
			}
			right++;
		}
	}

	/**
	 * 直接将非0的数字排好，再在数组的后续补充0
	 */
public:
	void moveZeroes_0(vector<int>& nums) {
		int index = 0;
		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] != 0) {
				nums[index] = nums[i];
				index++;
			}
		}

		for(int i = index; i < nums.size(); i++) {
			nums[i] = 0;
		}
	}
};