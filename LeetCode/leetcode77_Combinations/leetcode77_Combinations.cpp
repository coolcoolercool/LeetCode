#include "../../include.h"


/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。
 */

class Solution {
public:
	vector<vector<int>> res;
	void dfs(int n, int targetNum, int index, vector<int>& oneRes) {
		if (oneRes.size() == targetNum) {
			res.push_back(oneRes);
			return;
		} else {
			for(int i = index; i <= n; i++) {
				if(oneRes.size() + 1 <= targetNum) {
					oneRes.push_back(i);
					dfs(n, targetNum, i + 1, oneRes);
					oneRes.pop_back();
				}
			}
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<int> oneRes;
		dfs(n, k, 1, oneRes);

		return res;
	}
};

int main_54kmgft() {
	Solution sol;
	int n = 4;
	int k = 2;
	vector<vector<int>> res = sol.combine(n, k);

	for (auto vec_element : res) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}