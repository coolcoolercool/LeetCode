// Created by 周子望 on 2022/6/12.

/**
题目描述:
https://leetcode.cn/problems/isomorphic-strings/

核心思想:
**/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> help(string& str) {
		unordered_map<char, int> tMp;
		int tSize = str.size();
		vector<int> res;

		int tCnt = 0;
		for(int i = 0; i < tSize; i++) {
			if(tMp.count(str[i]) == 0) {
				res[i] = tCnt;
				tMp[str[i]] = tCnt;
				tCnt++;
			} else { // 出现了重复的字符
				int temp = tMp[str[i]];
				tMp[i] = temp;
			}
		}

		return res;
	}

	bool isIsomorphic(string s, string t) {
		unordered_map<char, int> tMp;
		unordered_map<char, int> sMp		;
		int tSize = t.size();
		vector<int> tVec = help(t);

		int sSize = s.size();
		vector<int> sVec = help(s);

		if(tVec == sVec) {
			return true;
		}

		return false;
	}
};

/**
"bbbaaaba"
"aaabbbba"
*/