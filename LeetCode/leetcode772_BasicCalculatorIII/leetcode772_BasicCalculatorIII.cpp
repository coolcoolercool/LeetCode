// Created by rainyzwzhou on 2022/5/21.

/**
题目描述:
实现一个基本的计算器来计算简单的表达式字符串。
表达式字符串可以包含左括号 (和右括号)，加号 + 和减号 -，非负 整数和空格 。
表达式字符串只包含非负整数， +, -, *, / 操作符，左括号 ( ，右括号 )和空格。整数除法需要向下截断。
你可以假定给定的字符串总是有效的。所有的中间结果的范围为 [-2147483648, 2147483647]。
一些例子：
"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
注：不要 使用内置库函数 eval。

核心思想:
 https://www.cnblogs.com/grandyang/p/8873471.html

**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		int n = s.size(), num = 0, curRes = 0, res = 0;
		char op = '+';
		for (int i = 0; i < n; ++i) {
			char c = s[i];
			if (c >= '0' && c <= '9') {
				num = num * 10 + c - '0';
			} else if (c == '(') {
				int j = i, cnt = 0;
				for (; i < n; ++i) {
					if (s[i] == '(') ++cnt;
					if (s[i] == ')') --cnt;
					if (cnt == 0) break;
				}
				num = calculate(s.substr(j + 1, i - j - 1));
			}
			if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
				switch (op) {
					case '+': curRes += num; break;
					case '-': curRes -= num; break;
					case '*': curRes *= num; break;
					case '/': curRes /= num; break;
				}
				if (c == '+' || c == '-' || i == n - 1) {
					res += curRes;
					curRes = 0;
				}
				op = c;
				num = 0;
			}
		}
		return res;
	}
};