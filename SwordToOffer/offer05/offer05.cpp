// Created by 周子望 on 2022/12/4.

/**
题目描述:

核心思想:
**/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		int count0 = 0, size = s.size();

		// 统计空格的数量
		for(char c : s) {
			if (c == ' ') count0++;
		}
		// 修改s的长度
		s.resize(size + 2 * count0);
		// 倒序遍历修改
		for(int i = size - 1, j = s.size() - 1; i < j; i--, j--) {
			if(s[i] != ' ') {
				s[j] = s[i];
			} else {
				s[j - 2] = '%';
				s[j - 1] = '2';
				s[j] = '0';
				j -= 2;
			}
		}
		return s;
	}


	string replaceSpace_ver0(string s) {
		string result;
		for(int i = 0; i < s.size(); i++) {
			if (s[i] != ' ') {
				result += s[i];
			} else {
				result += "%20";
			}
		}

		return result;
	}
};