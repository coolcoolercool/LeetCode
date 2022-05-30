// Created by rainyzwzhou on 2022/5/10.

/**
最大乘积，对于乘法，我们需要注意，负数乘以负数，会变成正数，所以解这题的时候我们需要维护两个变量，当前的最大值，以及最小值，最小值可能为负数，但没准下一步乘以一个负数，当前的最大值就变成最小值，而最小值则变成最大值了。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int curMax = nums[0], curMin = nums[0], res = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			int tempMin = curMax, tempMax = curMin;
			curMax = max(nums[i], max(tempMin * nums[i], tempMax * nums[i])); // 注意这里最大值和最小值的来源，共三个
			curMin = min(nums[i], min(tempMax * nums[i], tempMin * nums[i]));
			res = max(curMax, res);
		}
		return res;
	}
};

