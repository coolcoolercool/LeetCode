// Created by rainyzwzhou on 2022/5/22.

/**
题目描述:
给出由小写字母组成的字符串S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 S 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string removeDuplicates(string s) {
		string stk;
		for (char ch : s) {
			if (!stk.empty() && stk.back() == ch) {
				stk.pop_back();
			} else {
				stk.push_back(ch);
			}
		}
		return stk;
	}

public:
	stack<char> st;
	string removeDuplicates_0(string s) {
		for(int i = 0; i < s.size(); i++) {
			if(st.empty()) st.push(s[i]);
			if(st.top() == s[i]) {
				st.pop();
			} else {
				st.push(s[i]);
			}
		}

		string res;
		while(!st.empty()) {
			res.push_back(st.top());
			st.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};