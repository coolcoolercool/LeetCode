// Created by rainyzwzhou on 2022/4/26.

#include "../../include.h"

class LeetCode448 {
public:
	/*
		 将所有正数作为数组下标，置对应数组值为负值。那么，仍为正数的位置即为（未出现过）消失的数字。
		 理论: 就是把当前的数组当成一个hashmap，然后统计每个数字是否出现
	 */
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res;
		for(int i = 0; i < nums.size(); i++) {
			int index = abs(nums[i]) - 1;
			nums[index] = -abs(nums[index]);
		}

		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] > 0) res.push_back(i + 1);
		}
		return res;
	}

public:
	// 换位 swap 的方式
	vector<int> findDisappearedNumbers_ziji(vector<int>& nums) {
		for(int i = 0; i < nums.size(); i++) {
			while(nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		vector<int> res;
		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] != i + 1) {
				res.push_back(i + 1);
			}
		}
		return res;
	}

public:
	vector<int> findDisappearedNumbers_1(vector<int>& nums) {
		set<int> disSet;
		vector<int> res;

		for(int i = 0; i < nums.size(); i++) {
			disSet.insert(nums[i]);
		}

		for(int i = 1; i <= nums.size(); i++) {
			if(disSet.count(i) == 0) {
				res.push_back(i);
			}
		}
		return res;
	}
};