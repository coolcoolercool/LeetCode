// Created by rainyzwzhou on 2022/5/14.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int res = 0;
		int size = s.size();
		for (int i = 0; i < size; i++) { //遍历回文中心点
			for (int j = 0; j <= 1; j++) { //j=0,中心是一个点，j=1,中心是两个点
				int left = i;
				int right = i + j;
				while (left >= 0 && right < size && s[left--] == s[right++]) res++;
			}
		}
		return res;
	}
};