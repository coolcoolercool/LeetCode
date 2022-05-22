// Created by rainyzwzhou on 2022/5/11.

#include <bits/stdc++.h>
using namespace std;

class Solution {
	/**
	 * 思路
		如果将数组 nums 中的所有元素按照单调递增或单调递减的顺序排序，那么下标为 n/2 的元素（下标从 0 开始）一定是众数。
	 */
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};