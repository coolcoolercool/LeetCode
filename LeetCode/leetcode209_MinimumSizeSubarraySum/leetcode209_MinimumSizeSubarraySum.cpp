// Created by rainyzwzhou on 2022/5/30.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int> &nums) {
		int size = nums.size();
		int res = size + 1;
		int curSum = nums[0];
		int left = 0, right = 0;
		while (left <= right && right < size) {
			if (curSum >= target) {
				res = min(right - left + 1, res);
				curSum -= nums[left];
				left++;
			} else if (curSum < target) {
				right++;
				if (right < size) curSum += nums[right];;
			}
		}

		return res > size ? 0 : res;
	}

	int minSubArrayLen_001(int target, vector<int> &nums) {
		int size = nums.size();
		int res = size + 1;
		int curSum = 0;
		int left = 0, right = 0;
		for (int i = 0; i < size; ++i) {
			curSum += nums[i];
			while (left < i && curSum - nums[left] >= target) { // 维护最短符合要求的区间
				curSum -= nums[left++];
			}
			if (curSum >= target && i - left + 1 < curSum) curSum = i - left + 1;
		}

		return res > size ? 0 : res;
	}
};