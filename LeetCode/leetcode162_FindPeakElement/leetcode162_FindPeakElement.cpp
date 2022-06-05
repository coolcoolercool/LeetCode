// Created by rainyzwzhou on 2022/5/17.

/**
题目描述:

核心思想:
 过程：
（1）首先要注意题目条件，在题目描述中出现了 nums[-1] = nums[n] = -∞，这就代表着 只要数组中存在一个元素比相邻元素大，那么沿着它一定可以找到一个峰值
（2）根据上述结论，我们就可以使用二分查找找到峰值
（3）查找时，左指针 l，右指针 rLen，以其保持左右顺序为循环条件
（4）根据左右指针计算中间位置 m，并比较 m 与 m+1 的值，如果 m 较大，则左侧存在峰值，rLen = m，如果 m + 1 较大，则右侧存在峰值，l = m + 1

时间复杂度：O(logN)

**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while(left < right) {
			int mid = left + (right - left) / 2;
			if(nums[mid] > nums[mid + 1]) {  // 左边存在峰值
				right = mid;
			} else { // 右边存在峰值
				left = mid +1;
			}
		}

		return left;
	};
};

