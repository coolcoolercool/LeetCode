// Created by rainyzwzhou on 2022/5/12.

/**
* 题目描述:
*
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	/**
	 * dp[i] 表示 需要多少个数的平方来表示整数i
	 * 标签：动态规划
		（1）首先初始化长度为 n+1 的数组 dp，每个位置都为 0
		（2）如果 n 为 0，则结果为 0
		（3）对数组进行遍历，下标为 i，每次都将当前数字先更新为最大的结果，即 dp[i]=i，比如 i=4，最坏结果为 4=1+1+1+1 即为 4 个数字
		（4）动态转移方程为：dp[i] = MIN(dp[i], dp[i - j * j] + 1)，i 表示当前数字，j*j 表示平方数
		（5）时间复杂度：O(n*sqrt(n))，sqrt 为平方根
	 */
public:
	int numSquares(int n) {
		vector<int> dp(n +1); // 默认初始化值都为0

		for(int i = 1; i <= n; i++) {
			dp[i] = i;
			for(int j = 1; j * j <= i; j++) {
				dp[i] = min(dp[i], dp[i - j*j] + 1);  // 这一步主要是遍历所有可能到 dp[i] 的 之前一个数值dp[j]，遍历所有的j值，从中找到最小的
			}
		}

		return dp[n];
	}
};