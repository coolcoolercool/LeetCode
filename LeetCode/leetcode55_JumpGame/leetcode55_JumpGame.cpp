//
// Created by 周子望 on 2021/11/1.
//

/*
题目:
 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。

 https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode-solution/

 未完
 核心思想:
 对于数组中的任意一个位置 yy，我们如何判断它是否可以到达？根据题目的描述，只要存在一个位置 xx，它本身可以到达，并且它跳跃的最大长度为 x + \textit{nums}[x]x+nums[x]，
 这个值大于等于 y，即 x + {nums}[x]  yx+nums[x] ≥ y，那么位置 y 也可以到达。
换句话说，对于每一个可以到达的位置 x，它使得 x+1, x+2, \cdots, x+\textit{nums}[x]x+1,x+2,⋯,x+nums[x] 这些连续的位置都可以到达。

这样以来，我们依次遍历数组中的每一个位置，并实时维护 最远可以到达的位置。对于当前遍历到的位置 x，
如果它在 最远可以到达的位置 的范围内，那么我们就可以从起点通过若干次跳跃到达该位置，因此我们可以用 x + \textit{nums}[x]x+nums[x] 更新 最远可以到达的位置。
在遍历的过程中，如果 最远可以到达的位置 大于等于数组中的最后一个位置，那就说明最后一个位置可达，我们就可以直接返回 True 作为答案。反之，如果在遍历结束后，最后一个位置仍然不可达，我们就返回 False 作为答案。

 */


#include "../../include.h"

class Solution {
public:
	bool canJump(vector<int> &nums) {
		int n = nums.size(), right_most = 0;

		for (int i = 0; i < n; i++) {
			if (i <= right_most) {  // rightMost 表示目前可以到达最远的index的位置，index以及之前的索引都可以达到
				right_most = max(right_most, i + nums[i]);  // 比较之前的可以到达的最远的位置和当前位置可以到达最远的位置，取较大值

				if (right_most >= n - 1) return true;
			}
		}

		return false;
	}
};

int main_im41ok() {
	Solution sol;
	vector<int> nums;
	bool res;

	nums = {2, 3, 1, 1, 4};
	res = sol.canJump(nums);

	if (res) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	nums = {3, 2, 1, 0, 4};
	res = sol.canJump(nums);
	if (res) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	return 0;
}