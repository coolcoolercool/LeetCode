// Created by rainyzwzhou on 2022/5/23.

/**
题目描述:
找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

 解法有一个关键点是只有 nums[i] == i 的时候i才递增，这样保证找到相同元素前不会漏掉某些元素的处理

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int i = 0;
		while(i < nums.size()) {
			if (nums[i] == i) {
				i++;
				continue;
			} else {
				if (nums[nums[i]] == nums[i]) {
					return nums[i];
				}
				swap(nums[nums[i]], nums[i]);
			}
		}
		return -1;
	}
};