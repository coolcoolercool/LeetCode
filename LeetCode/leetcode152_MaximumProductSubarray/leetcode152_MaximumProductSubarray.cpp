// Created by rainyzwzhou on 2022/5/10.

/**
最大乘积，对于乘法，我们需要注意，负数乘以负数，会变成正数，所以解这题的时候我们需要维护两个变量，当前的最大值，以及最小值，最小值可能为负数，但没准下一步乘以一个负数，当前的最大值就变成最小值，而最小值则变成最大值了。
 */

#include <bits/stdc++.h>
#include "../../include.h"
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int curMax = nums[0], curMin = nums[0], ans = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			int tempMin = curMax, tempMax = curMin;
			curMax = max(tempMin * nums[i], max(nums[i], tempMax * nums[i]));
			curMin = min(tempMax * nums[i], min(nums[i], tempMin * nums[i]));
			ans = max(curMax, ans);
		}
		return ans;
	}
};

