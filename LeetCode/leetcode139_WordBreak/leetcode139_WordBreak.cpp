#include "../../include.h"

/**
https://leetcode17_LetterCombinationsOfAPhoneNumber-cn.com/problems/word-break/solution/dan-ci-chai-fen-by-leetcode17_LetterCombinationsOfAPhoneNumber-solution/

https://leetcode.cn/problems/word-break/solution/dong-tai-gui-hua-ji-yi-hua-hui-su-zhu-xing-jie-shi/
(1)初始化 dp=[False,⋯,False]，长度为 n+1。n 为字符串长度。dp[i] 表示 s 的前 ii 位是否可以用 wordDict 中的单词表示。
(2)初始化 dp[0]=True，空字符可以被表示。
(3)遍历字符串的所有子串，遍历开始索引 ii，遍历区间 [0,n)[0,n)：
	遍历结束索引 j，遍历区间 [i+1,n+1)：
	若 dp[i]=Trued 且 s[i,⋯,j) 在 wordlist 中：dp[j]=True。解释：dp[i]=True 说明 s 的前 i 位可以用 wordDict 表示，则 s[i,⋯,j) 出现在 wordDict 中，说明 s 的前 j 位可以表示。
(4)返回 dp[n]

 */
class Solution {
	// 初始化 dp=[False,⋯,False]，长度为 n+1。n 为字符串长度。dp[i] 表示 s 的前 i 位 就是s[0..i-1] 是否可以用 wordDict中的单词表示。
	// dp[i] = true 表示s字符串的 0~i-1的子串能够被匹配，只要加上i ~ x也能匹配，则0~x也能匹配

public:
	bool wordBreak(string& s, vector<string>& wordDict) {
		int strSize = s.size();
		vector<bool> dp(strSize + 1, false);
		dp[0] = true;
		for (int i = 0; i < strSize; i++) {
			if (!dp[i]) continue;
			for (auto &word : wordDict)
				if (word.size() + i <= dp.size() && s.substr(i, word.size()) == word)
					dp[i + word.size()] = true;
		}
		return dp[s.size()];
	}


/*
dp[i] 表示字符串 s 前 i 个字符组成的字符串 s[0..i-1] 是否能被空格拆分成若干个字典中出现的单词
 */
public:
	bool wordBreak_guanfang(string s, vector<string> &wordDict) {
		unordered_set<string> wordSet;
		for(auto element : wordDict) { // auto遍历后加&与不加有什么区别?  不加&的话每次都要把wordDict里的元素拷贝给word，加了就直接引用，不用拷贝，可以提高运行效率
			wordSet.insert(element);
		}

		vector<bool> dp(s.size() + 1);
		dp[0] = true;

		for(int i = 0; i <= s.size(); i++) {
			for(int j = 0; j < i; j++) {
				if (dp[j] && wordSet.count(s.substr(j, i - j)) != 0) {
					dp[i] = true;
					break;
				}
			}
		}

		return dp[s.size()];
	}
};

/*
 substr函数的形式为s.substr(pos, n)
 表示从 pos位置开始，往后返回 n 个字符，包括pos
 */

// Test
int main_0km7() {
	Solution sol;
	string s = "applepenapple";
	vector<string> wordDict = {"apple", "pen"};
	// 预期输出: true
	auto res = sol.wordBreak(s, wordDict);
	cout << (res == true ? "true" : "false");

	return 0;
}