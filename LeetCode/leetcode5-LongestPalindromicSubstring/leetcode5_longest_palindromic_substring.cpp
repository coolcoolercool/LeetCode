#include "../../include.h"

/**
 * 题目描述:
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * <p>
 *
 * 核心思想: 中心扩展算法
 * 使用恒定的空间，在时间复杂度为O(n^2)解决这个问题
 * 回文中心的两侧互为镜像，因此，回文可以在它的中心展开，并且只有 2*n-1个这样的中心。
 * n个中心是字母本身，剩下n-1个中心，是相邻字母之间的空格
 *
 * 基于中心点枚举的算法，时间复杂度 O(n^2)
 */
class Solution {
public:
	int help(string s, int left, int right) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			left--;
			right++;
		}

		return right - left - 1;  //  回文串的长度是right-left+1-2 = right - left - 1
	}

	string longestPalindrome(string s) {
		if(s.size() < 2) {
			return s;
		}

		int resLen = 0;
		int left = 0, right = 0;
		for(int i = 0; i < s.size(); i++) {
			int len1 = help(s, i, i);
			int len2 = help(s, i, i + 1);
			resLen = max(resLen, max(len1, len2));

			if(resLen > right - left + 1) {
				left = i - (resLen - 1) / 2;
				right = i + resLen / 2;
			};
		}

		return s.substr(left, right - left + 1);
	}

	// https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-nehzil-y1tc/
	string longestPalindrome_dp(string s) {
		string res;
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false));

		for(int i = 0; i < s.size(); i++) {
			dp[i][i] = true;
		}

		int maxLen = 0;
		int beginIndex = 0;
		for(int i = s.size() - 1; i >= 0; i--) {
			for(int j = i; j < s.size(); j++) {
				if(s[i] == s[j]){
					if(j - i <= 1) {
						dp[i][j] = true;
					} else if(dp[i + 1][j - 1]) {
						dp[i][j] = true;
					}

					if (dp[i][j] && j - i + 1 > maxLen) {
						maxLen = j - i + 1;
						beginIndex = i;
					}
				}
			}
		}
		/* 截取子串 */
		res = s.substr(beginIndex,maxLen);
		return res;
	}
};



