
#include "../../include.h"

/**
 * 题目描述:
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的数字可以无限制重复被选取。
 *
 * 说明：
 *
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。
 * 示例 1:
 *
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 *   [7],
 *   [2,2,3]
 * ]
 * 示例 2:
 *
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 *   [2,2,2,2],
 *   [2,3,3],
 *   [3,5]
 * ]
 *
 * 核心思想:
 * 给定数组中的元素可以重复取用
 * 这种结构可以看成是一类题，适用于许多其他回溯问题，这里展示子集，排列和组合和这三种题目
 */

class SolutionMethod2 {
public:
	vector<vector<int>> res;
	vector<int> oneRes;
	void help(vector<int>& candidates, int index, int remain) {
		if (remain == 0) {
			res.push_back(oneRes);
			return;
		}

		for (int i = index; i < candidates.size(); i++) {
			if (remain - candidates[i] >= 0) {
				oneRes.push_back(candidates[i]);
				help(candidates, i, remain - candidates[i]); // 因为可以重复使用，所以还是i (注意这里是i，不是index)
				oneRes.pop_back();   // 回溯，恢复现场
			}
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		help(candidates, 0, target);
		return res;
	}

};

class Solution {
public:
	/**
	 * @param one_combination_vector
	 * @param candidates
	 * @param index
	 * @param remain 每次减去 新加入 的candidates[mp]
	 * @param res 返回结果
	 */
	void recursion (vector<int>& one_combination_vector, vector<int>& candidates, int index, int remain, vector<vector<int>>& res) {
		if (index == candidates.size() || remain < 0) {
			return;
		}

		if (remain == 0) {
			res.push_back(one_combination_vector);
			return;
		}

		// 因为可以重复选择同一个元素，所以有两种情况，选择当前索引的元素和选择下一个索引的元素
		// 直接跳过当前的数
		recursion(one_combination_vector, candidates, index + 1, remain, res);

		// 选择当前的数
		if (remain - candidates[index] >= 0) {
			one_combination_vector.push_back(candidates[index]);
			recursion(one_combination_vector, candidates, index, remain - candidates[index], res);
			one_combination_vector.pop_back();  // 后退到之前一个状态，这个很重要
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> one_combination_vector;
		std::sort(candidates.begin(), candidates.end());
		recursion(one_combination_vector, candidates, 0, target, res);

		return res;
	}

};

int main_omah65() {
	SolutionMethod2 sol;
	vector<int> nums = {2,3,6,7};
	int target = 7;
	vector<vector<int>> res = sol.combinationSum(nums, target);

	for (auto vec_element : res) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}

