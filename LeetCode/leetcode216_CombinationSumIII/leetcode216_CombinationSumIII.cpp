// Created by rainyzwzhou on 2022/6/4.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/combination-sum-iii/solution/zu-he-zong-he-iii-by-leetcode-solution/

我们需要在 9 个数中选择 k 个数，让它们的和为 n。
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<int> oneRes;

	void help(int remain, int size, int index) {
		if (remain == 0 && size == oneRes.size()) {
			res.push_back(oneRes);
			return;
		} else {
			for (int i = index; i <= 9; i++) {
				if (remain - i >= 0) {
					oneRes.push_back(i);
					help(remain - i, size, i + 1);
					oneRes.pop_back();
				}
			}
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		help(n, k, 1);
		return res;
	}
};