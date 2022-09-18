// Created by 周子望 on 2022/6/13.

/**
题目描述:
https://leetcode.cn/problems/basic-calculator-ii/

核心思想:
https://leetcode.cn/problems/basic-calculator-ii/solution/chai-jie-fu-za-wen-ti-shi-xian-yi-ge-wan-zheng-ji-/
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	stack<int> num;  //存贮数字
	stack<char> op;  //存贮操作

	void eval() {
		int b = num.top();
		num.pop();
		int a = num.top();
		num.pop();
		char c = op.top();
		op.pop();
		int res;
		if (c == '+') res = a + b;
		else if (c == '-') res = a - b;
		else if (c == '*') res = a * b;
		else res = a / b;
		num.push(res);
	}

	int calculate(string s) {
		s = '0' + s;  // 对开头是负数的处理
		unordered_map<char, int> pr;
		pr['+'] = pr['-'] = 1, pr['*'] = pr['/'] = 2; //定义运算符的优先级
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c == ' ') continue;  // 跳过空格
			if (isdigit(c)) { // c是数字,读取一个连续的数字
				int x = 0, j = i;
				while (j < s.size() && isdigit(s[j])) {
					x = x * 10 + (s[j++] - '0');
				}

				num.push(x);    // 加入数字栈中
				i = j - 1;
			} else {     // c是操作符, op栈非空并且栈顶操作符优先级大于等于当前操作符c的优先级，进行eval()计算
				while (op.size() && pr[op.top()] >= pr[c]) eval();
				op.push(c);
			}
		}
		while (op.size()) eval();
		return num.top();
	}
};

class Solution_ver0 {
public:
	int calculate(string s) {
		int size = s.size();
		if (size == 0) return 0;

		stack<int> numSt;
		int res = 0;
		int num = 0;
		int topNum = 0;
		char ch = '+';
		for (int i = 0; i < size; i++) {
			while (i < size && isdigit(s[i])) { // 这里这么写，是因为如果到 i == size - 1，也需要到将数字压入栈
				num = num * 10 + int(s[i] - '0');
				i++;
			}

			if ((!isdigit(s[i]) && s[i] != ' ') || (i == size - 1)) {
				switch (ch) {
					case '+':
						numSt.push(num);
						break;
					case '-':
						numSt.push(-num);
						break;
					case '*':
						topNum = numSt.top();
						numSt.pop();
						numSt.push(topNum * num);
						break;
					case '/':
						topNum = numSt.top();
						numSt.pop();
						numSt.push(int(topNum / num));
						break;
				}
				ch = s[i];
				num = 0;
			}
		}

		while(!numSt.empty()) {
			res += numSt.top();
			numSt.pop();
		}

		return res;
	}
};