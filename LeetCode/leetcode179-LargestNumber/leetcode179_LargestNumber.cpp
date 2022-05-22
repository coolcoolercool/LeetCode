// Created by rainyzwzhou on 2022/4/26.

#include <bits/stdc++.h>
using namespace std;

class LeetCode179 {
public:
	string largestNumber(vector<int>& nums) {
		string resMaxNum;
		sort(nums.begin(), nums.end(), [](const int& left, const int& right) {
			long numBitsOfLeft = 10, numBitsOfRight = 10;

			// 这里是为了获取 left 和 right对应的位数，因为如果left在左边，那么就要往右边移动 right的位数个位置
			// eg. left=2, right=10  leftright = left * 10 + right
			while(numBitsOfLeft <= left) {
				numBitsOfLeft *= 10;
			}
			while(numBitsOfRight <= right) {
				numBitsOfRight *= 10;
			}

			return numBitsOfRight * left + right > numBitsOfLeft * right + left;
		});

		// 此时排序完，0应该在末尾，如果第一个字符仍然是0，说明全部都是0,直接返回"0"即可
		if(nums[0] == 0) {
			return "0";
		}
		for(int &x : nums) {
			resMaxNum += to_string(x);
		}
		return resMaxNum;
	}

	// 自定义比较器
	static bool cmp(const int& left, const int& right) {
		long leftLarge = 10, rightLarge = 10;

		while(leftLarge <= left) {
			leftLarge *= 10;
		}

		while(rightLarge <= right) {
			rightLarge *= 10;
		}

		return leftLarge * left + right > rightLarge * right + left;
	}

	// 直接使用全排列，在排列过程中，选择最大值，但是会超时
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

	string largestNumber_timeout(vector<int>& nums) {
		vector<int> one_permutations;
		string resMaxNum;
		vector<bool>(nums.size(), false);

		return resMaxNum;
	}
};