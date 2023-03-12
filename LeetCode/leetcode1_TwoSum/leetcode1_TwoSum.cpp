#include "../../include.h"

/*
题目:
给定一个整数数组 nums和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。
 */

class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		unordered_map<int, int> mp;
		for (int index = 0; index < nums.size(); index++) {
			if (mp.find(nums[index]) != mp.end()) {
				return vector<int>{mp[nums[index]], index};
			} else {
				mp[target - nums[index]] = index;
			}
		}
		return vector<int>{0, 0};
	}
};

// 这种方法无法处理，同一个元素不能在答案中出现两次的要求，比如 target = 6， nums {1,3,2,4}
// 需要再加一个判断，两个索引不一样
class Solution_Error {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> value_index_map;

		for (int i = 0; i < nums.size(); i++) {
			value_index_map[target - nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); i++) {
			if(value_index_map.count(nums[i]) != 0 && i != value_index_map[nums[i]]) {
				return vector<int> {i, value_index_map[nums[i]]};
			}
		}

		return vector<int>{0, 0};
	}

};

int main_insad () {
	Solution sol;
	vector<int> nums = {3,2,4};
	int target = 6;
	vector<int> res = sol.twoSum(nums, target);

	cout << "res[0]: " << res[0]  << endl;
	cout << "res[1]: " << res[1]  << endl;

	return 0;
};