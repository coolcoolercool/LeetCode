// Created by 周子望 on 2022/10/16.
#include "../../include.h"

/**
题目描述:

核心思想:
https://leetcode.cn/problems/set-mismatch/solutions/857255/cuo-wu-de-ji-he-by-leetcode-solution-1ea4/
 
a ^ a = 0
0 ^ a = a

a ^ a ^ a ^ b = a ^ b

桶排序
因为值的范围在 [1, n]，我们可以运用「桶排序」的思路，根据 nums[i] = i + 1 的对应关系使用 O(n) 的复杂度将每个数放在其应该落在的位置里。
然后线性扫描一遍排好序的数组，找到不符合 nums[i]=i+1 对应关系的位置，从而确定重复元素和缺失元素是哪个值。
**/

class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		int size = nums.size();
		for(int i = 0; i < size; i++) {
			while(nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}

		int dup_num = -1, defect_num = -1;
		for(int i = 0; i < size; i++) {
			if (nums[i] != i + 1) {
				dup_num = nums[i];
				defect_num = i == 0 ? 1 : nums[i - 1] + 1;
			}
		}

		return vector<int>{dup_num, defect_num};
	}

	// 哈希表解法
	vector<int> findErrorNums_hash(vector<int>& nums) {
		vector<int> errorNum(2);
		int size = nums.size();
		unordered_map<int, int> mp;

		for(int num : nums) {
			mp[num]++;
		}
		for(int i = 1; i <= size; i++) {
			int count = mp[i];
			if(count == 2) {
				errorNum[0] = i;
			} else if (count == 0) {
				errorNum[1] = i;
			}
		}

		return errorNum;
	}
};