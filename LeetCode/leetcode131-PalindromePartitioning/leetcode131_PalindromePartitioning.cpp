#include "../../include.h"

/*
题目:
 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 回文串 是正着读和反着读都一样的字符串。

 https://leetcode-cn.com/problems/palindrome-partitioning/solution/131-fen-ge-hui-wen-chuan-hui-su-sou-suo-yp2jq/
 */

class Solution {
private:
	vector<vector<string>> res;
	vector<string> path;

	void backstrarking(const string &s, int startIndex) {
		if (startIndex >= s.size()) {
			res.push_back(path);
			return;
		}

		for (int i = startIndex; i < s.size(); i++) {
			if (isPalindrome(s.substr(startIndex, i), startIndex, i)) {
				string str = s.substr(startIndex, i - startIndex + 1); // 注意这里的子串获取
				path.push_back(str);
			} else {
				continue;
			}

			backstrarking(s, i + 1);
			path.pop_back();
		}
	}

	bool isPalindrome(const string &s, int start, int end) {
		while (start < end) {
			if (s[start] != s[end]) {
				return false;
			}
			start++;
			end--;
		}
		return true;
	}

public:
	vector<vector<string>> partition(string s) {
		backstrarking(s, 0);

		return res;
	}
};

int main_okmn68() {
	Solution sol;
	string s = "aab";
	vector<vector<string>> res = sol.partition(s);

	for (auto vec_element : res) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}

