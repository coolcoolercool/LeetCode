#include "../include.h"

using namespace std;

class Solution {
public:
	void dfs_unique(vector<int> &nums, vector<bool> &used, string& maxNum, vector<int> &one_permutations) {
		// 递归终止条件
		if (one_permutations.size() == nums.size()) {
			string tempNum;
			for(int i = 0; i < one_permutations.size(); i++) {
				tempNum.append(to_string(one_permutations[i]));
			}
			maxNum = max(maxNum, tempNum);

			return;
		} else {
			for (int i = 0; i < nums.size(); i++) {
				if (used[i]) continue;

				// 剪枝条件：i > 0 是为了保证 nums[i - 1] 有意义
				// 写 !used[i - 1] 是因为 nums[i - 1] 在深度优先遍历的过程中刚刚被撤销选择
				if (i - 1 >= 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
					continue;
				}

				used[i] = true;
				one_permutations.push_back(nums[i]);
				//print_vector(oneRes, "递归之前: ");

				dfs_unique(nums, used, maxNum, one_permutations);

				// 回退到前一步
				used[i] = false;
				one_permutations.pop_back();
				//print_vector(oneRes, "递归之后: ");
			}
		}
	}

	string largestNumber(vector<int>& nums) {
		vector<int> one_permutations;
		string resMaxNum;
		vector<bool> used(nums.size());

		dfs_unique(nums, used, resMaxNum, one_permutations);

		return resMaxNum;
	}

};

static void print_vector(const vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ", ";
	}
	cout << endl;
}


int main_okmnj8() {
	Solution sol;
	vector<int> nums = {3,30,34,5,9};

	string str = "pwwkew";
	int target = 11;
	vector<int> res;
	string resStr;
	resStr = sol.largestNumber(nums);

	//print_vector(res);
	cout << "resStr: " << resStr << endl;

	return 0;
}


