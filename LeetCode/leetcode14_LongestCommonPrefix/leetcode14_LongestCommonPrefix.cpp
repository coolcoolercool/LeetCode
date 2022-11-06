// Created by rainyzwzhou on 2022/5/30.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		int size = strs.size();

		string res;
		if (size == 0) return res;
		for (int i = 0; i < strs[0].size(); i++) {
			char e = strs[0][i];
			for (auto &str : strs) {
				if (e != str[i]) return res;
			}
			res.push_back(e);
		}

		return res;
	}

	// 进阶做法，先排序然后比较头尾
	string longestCommonPrefix_0(vector<string> &strs) {
		string res;
		if (strs.empty()) return res;

		sort(strs.begin(), strs.end());
		string start = strs.front(), end = strs.back();
		int i, num = min(start.size(), end.size());
		for (i = 0; i < num && start[i] == end[i]; i++);

		return string(start, 0, i);
	}
};