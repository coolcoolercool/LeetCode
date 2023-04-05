// Created by rainyzwzhou on 2022/5/23.

/**
题目描述:
https://leetcode.cn/problems/string-to-integer-atoi/
请你来实现一个myAtoi(string s)函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数myAtoi(string s) 的算法如下：

（1）读入字符串并丢弃无用的前导空格
（2）检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
（3）读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
（4）将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
（5）如果整数数超过 32 位有符号整数范围 [−231, 231− 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231− 1 的整数应该被固定为 231− 1 。
（6）返回整数作为最终结果。

注意：
本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。


核心思想:
一旦涉及整数的运算，我们需要注意溢出。本题可能产生溢出的步骤在于推入、乘以 10 操作和累加操作都可能造成溢出。对于溢出的处理方式通常可以转换为 INT_MAX 的逆操作。比如判断某数乘以 10 是否会溢出，那么就把该数和 INT_MAX 除以 10 进行比较。

**/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	int myAtoi(string s) {
		int res = 0;
		int index = 0;
		int flag = 1;

		while(s[index] == ' ') index++; // 跳过空格
		if(s[index] == '-') flag = -1; // 如果存在 负号，记录 flag 为-1
		if(s[index] == '-' || s[index] == '+') index++; // 往下处理数字部分

		while(index < s.size() && isdigit(s[index])) { // isdigit 判断字符是否为十进制数字的字符
			int num = s[index] - '0';
			if(res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7)) { // 判断是否溢出 2147483647
				return flag > 0 ? INT_MAX : INT_MIN;
			}
			res = res * 10 + num;
			index++;
		}

		return flag * res;
	}

	// 这里判断有一种简单的做法， 就是将 res设置为long
	int myAtoi_1(string s) {
		long res = 0;
		int index = 0;
		int flag = 1;

		while(s[index] == ' ') index++; // 跳过空格
		if(s[index] == '-') flag = -1; // 如果存在 负号，记录 flag 为-1
		if(s[index] == '-' || s[index] == '+') index++; // 往下处理数字部分

		while(index < s.size() && isdigit(s[index])) { // isdigit 判断字符是否为十进制数字的字符
			int num = s[index] - '0';
			res = res * 10 + num;
			if ((flag && res > INT_MAX) || (!flag && res * -1 < INT_MIN)) {
				return flag > 0 ? INT_MAX : INT_MIN;
			}
			index++;
		}

		return flag * res;
	}

};

