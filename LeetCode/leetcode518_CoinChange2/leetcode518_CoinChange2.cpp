// Created by rainyzwzhou on 2022/5/29.

/**
题目描述:
https://leetcode.cn/problems/coin-change-2/solution/ling-qian-dui-huan-ii-by-leetcode-soluti-f7uh/

核心思想:
https://leetcode.cn/problems/coin-change-2/solution/ling-qian-dui-huan-ii-by-leetcode-soluti-f7uh/
 
动态规划的边界是 dp[0]=1。只有当不选取任何硬币时，金额之和才为 0，因此只有 1 种硬币组合。
对于面额为 coin 的硬币，当 coin≤i≤amount 时，如果存在一种硬币组合的金额之和等于 i−coin，则在该硬币组合中增加一个面额为 coin 的硬币，即可得到一种金额之和等于 i 的硬币组合。因此需要遍历 coins，对于其中的每一种面额的硬币，更新数组 dp 中的每个大于或等于该面额的元素的值。

 **/

#include <bits/stdc++.h>

using namespace std;


class Solution {
	// dp[x] 表示金额之和等于 x 的硬币组合数，目标是求 dp[amount]。
public:
	int change(int amount, vector<int> &coins) {
		vector<int> dp(amount + 1);
		dp[0] = 1;
		for (int &coin : coins) {
			for (int i = coin; i <= amount; i++) {
				dp[i] += dp[i - coin];
			}
		}
		return dp[amount];
	}
};