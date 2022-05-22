//
// Created by rainyzwzhou on 2022/4/27.
//

/**
给定一个长度为 n+1 的数组nums，数组中所有的数均在 1∼n 的范围内，其中 n≥1。
请找出数组中任意一个重复的数，但不能修改输入的数组。

数据范围
1≤n≤1000
样例
给定 nums = [2, 3, 5, 4, 3, 2, 6, 7]。
返回 2 或 3。

思考题：如果只能使用 O(1) 的额外空间，该怎么做呢？
 */

#include "../../../LeetCode/include.h"

class Solution {
public:
	// https://www.acwing.com/solution/content/8355/
	int duplicateInArray(vector<int>& nums) {
		int size = nums.size();
		int left = 1, right = size;
		while(left < right) {
			int mid = left + (right - left) / 2;  // 区间划分[left, mid], [mid + 1, right]，这里不是索引，是数值

			int count = 0; // 统计数组中位于左半区间的数的个数[l ,mid]
			for(auto element : nums) {
				if(element >= left && element <= mid) {
					count++;
				}
			}

			if(count > mid - left + 1) {  // 说明左边存在重复的数字，且重复的数字在 left~mid 之间
				right = mid;
			} else {
				left = mid + 1;
			}
		}

		return right;
	}
};