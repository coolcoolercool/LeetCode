// Created by rainyzwzhou on 2022/5/13.

/**
题目描述:
输入：s = "3[a]2[bc]"
输出："aaabcbc"

核心思想:
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	stack<int> numStack;
	stack<string> strStack;

	string decodeString(string s) {
		string res;  // 保存解码后的字符串结果

		int num = 0;
		int len = s.size();
		for (int i = 0; i < len; ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				num = num * 10 + s[i] - '0'; // 因为数字可能是多位数，并不一定只是一位数
			} else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				res.push_back(s[i]);
			} else if (s[i] == '[') {
				//将 [ 前的数字压入nums栈内， 字母字符串压入strs栈内。保存之前的计算结果
				numStack.push(num);
				num = 0;
				strStack.push(res);
				res = "";
			} else { //遇到 ] 时，操作与之相配的 [ 之间的字符，使用分配律
				int times = numStack.top();
				numStack.pop();
				string tempRes = strStack.top(); //之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
				strStack.pop(); //若是左括号，res会被压入strs栈，作为上一层的运算

				for (int j = 0; j < times; ++j) tempRes += res;
				res = tempRes;
			}
		}
		return res;
	}
};