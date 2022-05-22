#include "../../include.h"


/*
题目:给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 注意这里是可以在同一个子集中包含相同的元素的，比如 {2,2}


https://leetcode-cn.com/problems/subsets-ii/solution/90-zi-ji-iiche-di-li-jie-zi-ji-wen-ti-ru-djmf/

 (1)如何去重复？
 同一树枝上可以取重复的值，但是同一树层上不能取重复的值 ------ 理解“树层去重”和“树枝去重”非常重要
// used[i - 1] == true，说明同一树支candidates[i - 1]使用过
// used[i - 1] == false，说明同一树层candidates[i - 1]使用过
// 而我们要对同一树层使用过的元素进行跳过

 也可以使用set 去重


 */

class SolutionMethod {
private:
	vector<vector<int>> res;
	vector<int> oneRes;
	void help (vector<int>& nums, int startIndex) {
		res.push_back(oneRes);

		for (int i = startIndex; i < nums.size(); i++) {
			if (i > startIndex && nums[i - 1] == nums[i])  continue; 			// 注意这里是 i > starIndex，核心代码
			oneRes.push_back(nums[i]);
			help(nums, i + 1);
			oneRes.pop_back();
		}
	}


public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());  // 如果不是升序，需要先排列
		help(nums, 0);

		return res;
	}
};


class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;
	void dfs_subsetsWithDup (vector<int>& nums, vector<bool>& used ,int startIndex) {
		if (path.size() <= nums.size()) {
			res.push_back(path);
		}

		for (int i = startIndex; i < nums.size(); i++) {
			// used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
			// used[i - 1] == false，说明同一树层candidates[i - 1]使用过
			// 而我们要对同一树层使用过的元素进行跳过
			if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) {
				continue;
			}

			path.push_back(nums[i]);
			//print_vector(oneRes, "递归之前: " + to_string(startIndex) + " " );

			dfs_subsetsWithDup(nums, used, i + 1);

			path.pop_back();
			//print_vector(oneRes, "递归之前: " + to_string(startIndex) + " " );

		}
	}


public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<bool> used(nums.size());
		std::sort(nums.begin(), nums.end());

		dfs_subsetsWithDup(nums, used, 0);

		return res;
	}
};

int main_0mnh4() {
	SolutionMethod sol;
	vector<int> nums = {1,2,2};
	vector<vector<int>> res = sol.subsetsWithDup(nums);

	for (auto vec_element : res) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}
