#include "../../include.h"

/*
 题目: 给定一个数组candidates和一个目标数target，找出candidates中所有可以使数字和为target的组合。
candidates中的每个数字在每个组合中只能使用一次。
注意：解集不能包含重复的组合。
这里题目中，没有说数组中没有重复元素

 题解讲解:
 https://leetcode-cn.com/problems/combination-sum-ii/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-ig29/

 */

class SolutionMethod_2 {
public:
	vector<vector<int>> res;
	vector<int> path;

	void dfs_combinationSum2_2 (vector<int>& candidates, int remain, int startIndex) {
		if (remain == 0) {
			res.push_back(path);
			return;
		}

		for (int i = startIndex; i < candidates.size() && remain - candidates[i] >= 0; i++) {
			// 核心步骤: 去重处理
			if (i > startIndex && candidates[i] == candidates[i - 1]) { // 重点是有重复的数字，{1,1,7} 如果不去重，会有两个{1,7}
				continue;
			}

			remain -= candidates[i];
			path.push_back(candidates[i]);

			dfs_combinationSum2_2(candidates, remain, i + 1); // 不可重复取值，这里是i+1

			remain += candidates[i];
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		path.clear();
		res.clear();

		sort(candidates.begin(), candidates.end()); // 首先把给candidates排序，让其相同的元素都挨在一起。
		dfs_combinationSum2_2(candidates, target, 0);

		return res;
	}

};

class Solution {
public:
	void dfs_combinationSum2(int remain, int index, vector<int> &one_combination, vector<int> &candidates,
	                         vector<vector<int>> &res) {
		if (remain == 0) {
			res.push_back(one_combination);
			return;
		}


		if (remain < 0 || index >= candidates.size()) {
			return;
		}

		// 01 背包
		// (1)选择当前数
		int candidate = candidates[index];

		one_combination.push_back(candidate);
		dfs_combinationSum2(remain - candidate, index + 1, one_combination, candidates, res);
		one_combination.pop_back();

		// (2)不选择当前数
		while(index < candidates.size() && candidates[index] == candidate) {
			index++;
		}

		if (index < candidates.size() && remain - candidates[index] < 0) {
			return;
		}

		dfs_combinationSum2(remain, index, one_combination, candidates, res);
	}

	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		vector<vector<int>> res;
		vector<int> one_combination;
		vector<bool> used(candidates.size());

		// 先对数组排序
		std::sort(candidates.begin(), candidates.end());

		dfs_combinationSum2(target, 0, one_combination, candidates, res);

		return res;
	}
};

class SolutionMethod_3 {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
		if (sum == target) {
			result.push_back(path);
			return;
		}
		for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
			// 要对同一树层使用过的元素进行跳过
			if (i > startIndex && candidates[i] == candidates[i - 1]) {
				continue;
			}
			sum += candidates[i];
			path.push_back(candidates[i]);
			backtracking(candidates, target, sum, i + 1); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
			sum -= candidates[i];
			path.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		path.clear();
		result.clear();
		// 首先把给candidates排序，让其相同的元素都挨在一起。
		sort(candidates.begin(), candidates.end());
		backtracking(candidates, target, 0, 0);
		return result;
	}

};


int main_omhn5() {
	SolutionMethod_2 sol;
	vector<int> nums = {10,1,2,7,6,1,5};
	int target = 8;
	vector<vector<int>> res = sol.combinationSum2(nums, target);

	for (auto vec_element : res) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}

/*



 */
