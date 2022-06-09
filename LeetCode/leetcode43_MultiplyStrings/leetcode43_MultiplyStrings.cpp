// Created by rainyzwzhou on 2022/5/30.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") return "0";

		int size1 = num1.size(), size2 = num2.size();
		vector<int> res(size1 + size2); // 比原来要多一位，用于储存进位使用

		for (int i = size1 - 1; i >= 0; i--) { // 每次乘积的数字按照从后往前挨个放置
			int x = num1[i] - '0';
			for (int j = size2 - 1; j >= 0; j--) {
				int y = num2[j] - '0';
				res[i + j + 1] += x * y; // 注意这是 += 因为后续十位百位等也会将对应的数字累加到这里
			}
		}

		for (int i = size1 + size2 - 1; i > 0; i--) {
			res[i - 1] += res[i] / 10;
			res[i] %= 10;
		}

		int index = res[0] == 0 ? 1 : 0; // 有没有进位数字

		string ans;
		while (index < size1 + size2) {
			ans.push_back(res[index] + '0');
			index++;
		}

		return ans;
	}
};