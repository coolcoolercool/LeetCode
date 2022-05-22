// Created by rainyzwzhou on 2022/5/18.

/**
题目描述:  https://leetcode.cn/problems/repeated-substring-pattern/
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	// https://leetcode.cn/problems/repeated-substring-pattern/solution/zhong-fu-de-zi-zi-fu-chuan-by-leetcode-solution/
public:
	bool repeatedSubstringPattern(string s) {
		return (s + s).find(s, 1) != s.size();
	}

public:
	bool repeatedSubstringPattern_0(string s) {
		int size = s.size();
		for (int i = 1; i * 2 <= size; ++i) {
			if (size % i == 0) {
				bool match = true;
				for (int j = i; j < size; ++j) {
					if (s[j] != s[j - i]) {
						match = false;
						break;
					}
				}
				if (match) return true;
			}
		}
		return false;
	}
};

