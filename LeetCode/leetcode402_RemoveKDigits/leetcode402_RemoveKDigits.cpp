// Created by rainyzwzhou on 2022/5/19.

/**
题目描述:
给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

核心思想:
贪心 + 单调栈
https://leetcode.cn/problems/remove-k-digits/solution/wei-tu-jie-dan-diao-zhan-dai-ma-jing-jian-402-yi-d/

对于每个数字，如果该数字小于栈顶元素，我们就不断地弹出栈顶元素，直到
(1)栈为空
(2)或者新的栈顶元素不大于当前数字
(3)或者我们已经删除了 kk 位数字

针对一些情况做额外的处理：
(1)如果我们删除了 m 个数字且 m<k，这种情况下我们需要从序列尾部删除额外的 k-m 个数字。
(2)如果最终的数字序列存在前导零，我们要删去前导零。
(3)如果最终数字序列为空，我们应该返回 0。

**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		vector<char> vec;  // 这里没有直接使用stack，而是使用了vec，是因为后续需要从头到尾遍历
		for (auto &digit: num) {
			while (!vec.empty() && vec.back() > digit && k > 0) { // 只要k>0且当前的c比栈顶的小，则栈顶出栈，k--
				vec.pop_back();
				k--;
			}
			vec.push_back(digit);
		}

		for (; k > 0; --k) vec.pop_back(); // 删除了 m 个数字且 m<k，这种情况下我们需要从序列尾部删除额外的 k−m 个数字. 如果使用while，记得更新k值

		string res;
		bool isBeginZero = true; // 表示开头是否为0
		for (auto &digit: vec) {
			if (isBeginZero && digit == '0') continue;
			isBeginZero = false;
			res += digit;
		}
		return res == "" ? "0" : res;
	}
};
