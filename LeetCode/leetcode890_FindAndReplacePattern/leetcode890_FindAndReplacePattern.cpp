// Created by 周子望 on 2022/6/12.

/**
题目描述:

核心思想:
把两个字符串的模式映射成同一个的模式
abbc
deef
->
0112
**/

#include <bits/stdc++.h>
using namespace std;

// 将所有的word和pattern映射成一个模式字符，只要模式字符一样，则符合
class Solution {
public:
	vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
		string P = rebuildWord(pattern);
		vector<string> res;
		for (auto &word: words)
			if (rebuildWord(word) == P) res.push_back(word);

		return res;
	}

	string rebuildWord(string &word) {
		char cur = 'a';
		unordered_map<char, char> mp;
		string newWord;
		for (auto &ch: word) {
			if (!mp.count(ch))
				mp[ch] = cur++;
			newWord += mp[ch];
		}
		return newWord;
	}
};


// 将word的字符映射到 pattern字符中
class Solution_ver0 {
private:
	bool match(string &word, string &pattern) {
		unordered_map<char, char> mp;
		for (int i = 0; i < word.length(); ++i) {
			char chW = word[i], chP = pattern[i];
			if (mp.count(chW) == 0) {
				mp[chW] = chP;
			} else if (mp[chW] != chP) { // word 中的同一字母必须映射到 pattern 中的同一字母上
				return false;
			}
		}
		return true;
	}

public:
	vector<string> findAndReplacePattern(vector<string> &words, string &pattern) {
		vector<string> ans;
		for (auto &word: words) {
			if (match(word, pattern) && match(pattern, word)) {
				ans.emplace_back(word);
			}
		}
		return ans;
	}
};


