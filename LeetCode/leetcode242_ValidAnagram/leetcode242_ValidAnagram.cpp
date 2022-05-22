// Created by rainyzwzhou on 2022/5/21.

/**
题目描述:
https://leetcode.cn/problems/valid-anagram/
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若s 和 t中每个字符出现的次数都相同，则称s 和 t互为字母异位词。

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> sVec(26);
		vector<int> tVec(26);

		for(auto e : s) {
			sVec[e - 'a']++;
		}
		for(auto e : t) {
			tVec[e - 'a']++;
		}

		return sVec == tVec;
	}

	bool isAnagram_0(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		return s == t;
	}
};