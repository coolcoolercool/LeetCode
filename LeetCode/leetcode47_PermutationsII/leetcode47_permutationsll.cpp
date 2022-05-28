#include "../../include.h"

/**
 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 2 2'
 因为2' 2 和 2 2' 在结果看是一样，只需要取一种情况就可以，
 对于nums每一个元素都会选中，如果一开始选中的是2，则后续 2 2'
 后续遍历到 2' 的时候，如果发现 前一个数字(i - 1)跟当前的数字(i)相同，且当前状态是false，说前一次已经取过这个数字了，现在来到 2' 的循环，因此直接跳过 2' 的情况

如果前一个重复元素没有使用过，那么在当前重复元素下一层的可选项中一定会存在，也就是绿色部分
那么一定会重复，即出现 2 X = X 2' 的情况（X为不选）
也就是2和2' 以及 2'和2一定会重复，则整体剪枝，且是提前剪枝，在红色选择处就剪枝

 https://leetcode.cn/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/
 */

class Solution {
public:
	vector<vector<int>> res;
	vector<int> oneRes;

	void dfs_unique(vector<int> &nums, vector<bool> &visited) {
		// 递归终止条件
		if (oneRes.size() == nums.size()) {
			res.push_back(oneRes);
			return;
		} else {
			for (int i = 0; i < nums.size(); i++) {
				if (visited[i]) continue;

				// 剪枝条件：i > 0 是为了保证 nums[i - 1] 有意义。写 !used[i - 1] 是因为 nums[i - 1] 在深度优先遍历的过程中刚刚被撤销选择
				if (i - 1 >= 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) continue;

				visited[i] = true;
				oneRes.push_back(nums[i]);

				dfs_unique(nums, visited);
				visited[i] = false;                // 回退到前一步
				oneRes.pop_back();
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		vector<bool> visited(nums.size());

		dfs_unique(nums, visited);
		return res;
	}
};

int main_0mjng() {
	Solution sol;
	vector<int> nums = {1,1,2};
	vector<vector<int>> res = sol.permuteUnique(nums);

	for (auto vec_element : res) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}



