// Created by 周子望 on 2021/11/8.

/*
题目: 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

 */

#include "../../include.h"

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;

		int f1 = 0, f2 = 0, f3 = 1;
		for (int i = 1; i <= n; i++) {
			f1 = f2;
			f2 = f3;
			f3 = f1 + f2;
		}

		return f3;
	}

	/**
		本问题其实常规解法可以分成多个子问题，爬第n阶楼梯的方法数量，等于 2 部分之和
		爬上 n-1 阶楼梯的方法数量。因为再爬1阶就能到第n阶
		爬上 n-2 阶楼梯的方法数量，因为再爬2阶就能到第n阶
		所以我们得到公式 dp[n] = dp[n-1] + dp[n-2]
		同时需要初始化 dp[0]=1 和 dp[1]=1
	 */
	int climbStairs_dp(int n) {
		// select[n] 表示到第n阶梯的方法总数
		vector<int> dp(n + 1);
		dp[0] = 0, dp[1] = 1, dp[2] = 2;

		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}

	// 进阶如何打印跳跃的台阶
	int cnt = 0;
	vector<string> res;

	void dfs(int n, int cur, string s) {
		if (cur == n) {
			cnt++;
			res.push_back(s);
			return;
		}
		if (cur > n) return;
		dfs(n, cur + 1, s + to_string(cur + 1));
		dfs(n, cur + 2, s + to_string(cur + 2));
	}
};

int main_9mjnw () {
	Solution sol;
	int n = 3;
	int res = sol.climbStairs(n);
	cout << "res: " << res << endl;

	n = 4;
	res = sol.climbStairs(n);
	cout << "res: " << res << endl;

	n = 1;
	res = sol.climbStairs(n);
	cout << "res: " << res << endl;

	return 0;
}