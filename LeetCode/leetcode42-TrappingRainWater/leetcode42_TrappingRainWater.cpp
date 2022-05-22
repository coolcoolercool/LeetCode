#include "../../include.h"

/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 题解讲解:
 https://leetcode-cn.com/problems/combination-sum-ii/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-ig29/

复杂度分析
时间复杂度：O(n)，其中 nn 是数组 height 的长度。两个指针的移动总次数不超过 n。
空间复杂度：O(1)。只需要使用常数的额外空间。

核心思想:
求每一列的水，我们只需要关注当前列，以及左边最高的墙，右边最高的墙就够了。
现在想象一下，往两边最高的墙之间注水。正在求的列会有多少水？

两个指针，left 和 right，分别从两头开始遍历，在移动中维护当前左边最高的值 和 右边最高的值
每次遍历到当前的列，使用min(leftMax, rightMax) - height[curIndex], 就是当前列能接的雨水

 可能的情况
 (1) 当前列，跟min(leftMax, rightMax) 相等，接不到雨水
 (2) 当前列，比min(leftMax, rightMax) 小，能接到雨水

 */
class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		int left = 0, right = height.size() - 1;
		int leftMax = 0, rightMax = 0;
		while (left < right) {
			leftMax = max(leftMax, height[left]);
			rightMax = max(rightMax, height[right]);

			if (leftMax < rightMax) { // 谁矮谁移动
				ans += leftMax - height[left];
				left++;
			} else {
				ans += rightMax - height[right];
				right--;
			}
		}

		return ans;
	}
};

int main_omlh12() {
	Solution sol;
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	int res = sol.trap(height);

	cout << res << endl;

	return 0;
}
