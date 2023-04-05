// Created by rainyzwzhou on 2022/6/3.

/**
题目描述:
https://leetcode.cn/problems/longest-common-subsequence/

核心思想:
有点类似与编辑距离

dp[i][j]表示 text1[0:i-1] 和 text2[0:j-1]的最长公共子序列。（注：text1[0:i-1] 表示的是 text1 的 第 0 个元素到第 i - 1 个元素，两端都包含）

https://leetcode.cn/problems/longest-common-subsequence/solution/zui-chang-gong-gong-zi-xu-lie-by-leetcod-y7u0/
上面的图
 https://leetcode.cn/problems/longest-common-subsequence/solution/fu-xue-ming-zhu-er-wei-dong-tai-gui-hua-r5ez6/
下面的解析
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// LCS
	// dp[i][j] 表示 str1[0:i-1] 和 str2[0:j-1] 的最长公共子序列的长度, 所以比较的是str1[i-1]和str2[j-1]
	// dp[size1][size2] 表示 str1 和 str2 的最长公共子序列的长度
	int longestCommonSubsequence(string text1, string text2) {
		int size1 = text1.size(), size2 = text2.size();
		vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));

		for (int i = 1; i <= size1; i++) {
			char c1 = text1[i - 1];
			for (int j = 1; j <= size2; j++) {
				char c2 = text2[j - 1];
				if (c1 == c2) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[size1][size2];
	}

	// 进阶如何打印 最长公共子序列
	int longestCommonSubsequence_forPrint(string text1, string text2) {
		int size1 = text1.size(), size2 = text2.size();
		vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));

		for (int i = 1; i <= size1; i++) {
			char c1 = text1[i - 1];
			for (int j = 1; j <= size2; j++) {
				char c2 = text2[j - 1];
				if (c1 == c2) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		// -------- 打印最长公共子序列 start，根据递推公式反推 dp[][] 二维数组的性质
		string resStr;
		// 从右下角反向遍历二维数组，找最长公共子序列。注意！需要记录长度，从而避免受到其他子序列的干扰
		int count = dp[size1][size2];
		bool flag = false;
		for (int i = size1; i > 0; i--) {
			if (flag) break;
			for (int j = size2; j > 0; j--) {
				if (dp[i][j] == count && dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1]) {
					resStr.push_back(text1[i - 1]);
					count--;
					if (count == 0) {    // 优化：找完了可以提前跳出所有循环~
						flag = true;
						break;
					}
					break; // 优化：这一层找到了就可以跳出这层循环
				}
			}
		}
		reverse(resStr.begin(), resStr.end());
		cout << resStr << endl;
		// -------- 打印最长公共子序列 end
		return dp[size1][size2];
	}
};

/**
附送两组测试用例：
"abcda"
"dcba"
结果：2 "da"
"acdaba"
"badaa"
结果：4 "adaa"
**/