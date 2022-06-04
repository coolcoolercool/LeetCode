// Created by rainyzwzhou on 2022/6/3.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/palindrome-number/solution/hua-jie-suan-fa-9-hui-wen-shu-by-guanpengchn/
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	bool isPalindrome(int x) {
		if (x < 0) return false;

		int cur = 0;
		int num = x;
		while (num != 0) {
			if (cur > INT_MAX / 10 || (cur == INT_MAX && num % 10 > 7)) {
				return false;
			}
			cur = cur * 10 + num % 10;
			num /= 10;
		}
		return cur == x;
	}

	// 当然最简单的还是变成字符串，reverse比较一下即可
};
