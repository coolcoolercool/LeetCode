#include "../../include.h"

/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 https://leetcode-cn.com/problems/subsets/solution/c-zong-jie-liao-hui-su-wen-ti-lei-xing-dai-ni-gao-/
 (1)递归终止条件是什么
此题非常特殊，所有路径都应该加入结果集，所以不存在结束条件。或者说当 start 参数越过数组边界的时候，程序就自己跳过下一层递归了，
 因此不需要手写结束条件,直接加入结果集,表现在往常的递归终止条件的地方没有返回

 DFS和回溯法主要区别在于状态重置，DFS在访问过一个结点之后会标记为访问过，这个标记不会被撤销。回溯法也会对结点进行标记，但是在回溯之后会撤销这个标记。例如寻找条路径，DFS在找到一条后就会结束，回溯法可以将所有的路径找到。

 2022-12-04
 */

class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void dfs (vector<int>& nums,int startIndex) {
		if (path.size() <= nums.size()) res.push_back(path); 		// 注意这里的添加单个可能的条件，并没有返回，因为是子集
		for (int i = startIndex; i < nums.size(); i++) {
			path.push_back(nums[i]);
			dfs(nums, i + 1);  // 注意这里是 i+ 1， 不是 startIndex + 1
			path.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		dfs (nums, 0);
		return res;
	}
};

int main_78jnng() {
	Solution sol;
	vector<int> nums = {1,2,3};
	vector<vector<int>> res = sol.subsets(nums);

	for (auto vec_element : res) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}

	nums = {0};
	res = sol.subsets(nums);

	for (auto vec_element : res) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}