// Created by 周子望 on 2022/6/11.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/flip-string-to-monotone-increasing/solution/zui-gui-fan-de-dong-tai-gui-hua-xie-fa-d-82le/

写动态规划看状态转移方程，写状态转移方程看定义状态。
定义dp[i][0], dp[i][0]表示前i个元素递增且第i个元素为0的最小翻转次数，
定义dp[i][1]， dp[i][1]表示前i个元素递增且第i个元素为1的最小翻转次数。
	由定义可知，如果前i个元素最后以0结尾且满足单调递增，那么前i个元素必须全部为0，由此可得dp[i][0]的状态转移如下：
	dp[i][0] = dp[i-1][0] + (s.charAt(i)=='0'?0:1);
	由定义可知， dp[i][1]只要满足最后一个元素为1就行，那么前i-1个元素既可以为0，也可以为1，因此dp[i][1]的状态转移如下：
	dp[i][1] = min(dp[i-1][1], dp[i-1][0]) + (s.charAt(i)=='1'?0:1)；
最后取dp[i][0],dp[i][1]中的较小的即可。

**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	// 动态规划的解法
	// dp[i][0]表示前i个元素，最后一个元素为0的最小翻转次数；
	// dp[i][1]表示前i个元素，最后一个元素为1的最小翻转次数
public:
	int minFlipsMonoIncr(string s) {
		int size = s.size();
		vector<vector<int>> dp(size, vector<int>(2));
		//初始化
		dp[0][0] = s[0] == '0' ? 0 : 1;
		dp[0][1] = s[0] == '1' ? 0 : 1;
		//状态转移
		for (int i = 1; i < s.length(); i++) {
			dp[i][0] = dp[i - 1][0] + (s[i] == '0' ? 0 : 1); // 如果s[i] 为1，则需要将1改为0
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (s[i] == '1' ? 0 : 1); // 如果s[i] 为0，则需要将0改为1
		}

		return min(dp[size - 1][0], dp[size - 1][1]);
	}
};

/**
前缀和
预期是前一部分是0，后一部分是1。那么以某个索引index为分界点，则需要保证index之前都是0，index以后都是1。那么只需要将index之前的1都变成0，将index后的0都变成1。
遍历每一个索引，同时计算索引前面的1和后面的0的数量，就是需要翻转的数量
**/
class Solution_ver0 {
public:
	int minFlipsMonoIncr(string s) {
		int size = s.size();
		vector<int> preSum(size + 1);
		for (int i = 0; i < size; ++i) {
			preSum[i + 1] = preSum[i] + (s[i] - '0');
		}

		int res = INT_MAX;
		for (int i = 0; i <= size; ++i) {
			res = min(res, preSum[i] + (size - i - (preSum[size] - preSum[i]))); // 当前字符前面1的数量  当前字符包括当前字符后面0的数量
		}
		return res;
	}
};
