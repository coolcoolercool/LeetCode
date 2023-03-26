#include "../../include.h"

/**
 * 题目描述:
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 *
 * 示例:
 *
 * 输入: [1,2,3]
 * 输出:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 *
 * 核心思想:
 * 回溯算法，这里的递归比较复杂，很难理解
 * 回溯法：一种通过探索所有可能的候选解来找出所有的解的算法。如果候选解被确认不是一个解（或者至少不是最后一个解），回溯算法会通过在上一步进行一些变化抛弃该解，即回溯
 //1. 每个元素都只能选 1 次，需要 visited 数组标记是否访问
 //2. 排列问题，不需设置 startIndex;
 //3. 不含重复元素，不需要在同一层去重,不需要排序

 这一个类型的题目:并且再次尝试。

 https://leetcode.cn/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
 *
 */

class Solution {
public:
	vector<vector<int>> res;
	vector<int> oneRes;
	void dfs(vector<int>& nums, vector<bool>& used) {
		// 递归终止条件
		if (oneRes.size() == nums.size()) {
			res.push_back(oneRes);
		} else {
			for (int i = 0; i < nums.size(); i++) {
				if (used[i]) continue;   // 如果已经使用过，则直接跳过
				used[i] = true;
				oneRes.push_back(nums[i]);
				dfs(nums, used);
				used[i] = false;
				oneRes.pop_back();
			}
		}
	}

	vector<vector<int>> permute(vector<int> &nums) {
		vector<bool> used(nums.size());
		dfs(nums, used);
		return res;
	}
};


class Solution_ziji {
	// 扩展，出现过子集全排列
	// 题目描述: 给定一个数组，给定一个数字count，表示从数组中挑选count个元素，组成一个子集排列。返回所有的这种排列
public:
	vector<string> res;
	string oneRes;

	void help(vector<char> &nums, int k, vector<bool> &visited) {
		if (oneRes.size() == k) {
			res.push_back(oneRes);
		} else {
			for (int i = 0; i < nums.size(); i++) {
				if (oneRes.size() < k) {
					if (visited[i] == true) continue;
					oneRes.push_back(nums[i]);
					visited[i] = true;

					help(nums, k, visited);

					visited[i] = false;
					oneRes.pop_back();
				}
			}
		}
	}

	vector<string> test(int k, int b) {
		vector<char> nums;
		int c = 'a';
		for (; b > 0; b--) {
			nums.push_back(c);
			c++;
		}

		vector<bool> visited(nums.size());
		help(nums, k, visited);

		return res;
	}

};

int main_9nmh5() {
	Solution sol;
	vector<int> nums = {1, 2, 3};
	vector<vector<int>> res = sol.permute(nums);

	for (auto vec_element : res) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}


