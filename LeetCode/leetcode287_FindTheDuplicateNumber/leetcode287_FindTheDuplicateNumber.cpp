// Created by rainyzwzhou on 2022/5/13.

#include <bits/stdc++.h>
using namespace std;

class Solution {
	/**
	 * 简单来说，因为数组数字在[1, n]，而数组索引值[0, n]，那么数组就可以构成一个环形链表，我们可以使用nums[nums[i]]来表示nums[i].
		那么问题就转化成了142. 环形链表 II，这里不多解释。

	  快慢指针思想, fast 和 slow 是指针, nums[slow] 表示取指针对应的元素
        注意 nums 数组中的数字都是在 1 到 n 之间的(在数组中进行游走不会越界),
        因为有重复数字的出现, 所以这个游走必然是成环的, 环的入口就是重复的元素,
        即按照寻找链表环入口的思路来做
    */
public:
	int findDuplicate(vector<int>& nums) {
		int fast = 0, slow = 0;
		while(true) {
			fast = nums[nums[fast]];
			slow = nums[slow];

			if(slow == fast) {  // 快慢指针重合，此时从头结点和慢指针同时一步一步走，那么再重合的时候，就是链表环的入口
				fast = 0;
				while(nums[slow] != nums[fast]) {
					fast = nums[fast];
					slow = nums[slow];
				}
				return nums[slow];
			}
		}

		return -1;
	}

	/**
	 * 标记法
	 * 考虑到数组元素值的范围是[1, n]，但数组长度为n + 1，那么很显然在遍历数组的时候，我们将数组的值变为其对应的负数，那么再次遇到负数就得到了答案。
	 */
public:
	int findDuplicate_0(vector<int>& nums) {
		// 这里必须要在一次遍历中修改和检查
		for (int element : nums) {
			int index = abs(element);
			if (nums[index] < 0) {
				return index;
			}
			nums[index] = -nums[index];
		}

		return -1;
	}
};
