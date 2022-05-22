// Created by rainyzwzhou on 2022/5/20.

/**
题目描述:
https://leetcode.cn/problems/add-strings/
 
给定两个字符串形式的非负整数num1 和num2，计算它们的和并同样以字符串形式返回。
你不能使用任何內建的用于处理大整数的库（比如 BigInteger），也不能直接将输入的字符串转换为整数形式。


核心思想:
 
**/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	string addStrings(string num1, string num2) {
		string res;
		int add = 0;
		int size1 = num1.size(), size2 = num2.size();
		int olderSize = max(size1, size2) - 1;
		int curIndex = 0;

		while(curIndex <= olderSize) {
			int val1 = curIndex >= size1 ? 0 : num1[size1 - curIndex - 1] - '0';
			int val2 = curIndex >= size2 ? 0 : num2[size2 - curIndex - 1] - '0';

			int sum = val1 + val2 + add;
			add = sum / 10;
			sum = sum % 10;

			res.append(to_string(sum));
		}
		if(add > 0) res.append(to_string(add));
		reverse(res.begin(), res.end());

		return res;
	}
};

