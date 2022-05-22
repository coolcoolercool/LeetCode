// Created by rainyzwzhou on 2022/5/1.

/**
 题目:

 */

#include "../../include.h"

class Solution {
	/**
	在此方法中，我们利用两个计数器left 和 right 。首先，我们从左到右遍历字符串，对于遇到的每个 (’，我们增加left 计数器，对于遇到的每个 ‘)’ ，我们增加 right 计数器。每当left 计数器与 right 计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串。当 right 计数器比left 计数器大时，我们将left 和 right 计数器同时变回 0。

这样的做法贪心地考虑了以当前字符下标结尾的有效括号长度，每次当右括号数量多于左括号数量的时候之前的字符我们都扔掉不再考虑，重新从下一个字符开始计算，但这样会漏掉一种情况，就是遍历的时候左括号的数量始终大于右括号的数量，即 (() ，这种时候最长有效括号是求不出来的。

解决的方法也很简单，我们只需要从右往左遍历用类似的方法计算即可，只是这个时候判断条件反了过来：
当left 计数器比 right 计数器大时，我们将left 和 right 计数器同时变回 0
当left 计数器与 right 计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串

*/
public:
	int longestValidParentheses(string s) {
		int length = s.size();
		int left = 0, right = 0, res = 0;
		for(int i = 0; i < length; i++) {
			if (s[i] == '(') left++;
			else right++;

			if (left == right) res = max(res, 2 * right);
			else if (right > left) left = right = 0;
		}

		left = right = 0;
		for (int i = length - 1; i >= 0; i--) {
			if (s[i] == '(') left++;
			else right++;

			if (left == right) res = max(res, 2 * left);
			else if (left > right) left = right = 0;
		}

		return res;
	}

public:
	/**
	我们知道栈在处理括号匹配有着天然的优势，于是考虑用栈去判断序列的合法性。遍历整个字符串s，把所有的合法括号序列按照右括号来分类，对于每一个右括号，都去求一下以这个右括号为右端点的最长的合法括号序列的左端点在什么位置。我们把每个右括号都枚举一遍之后，再取一个max，就是整个的最大长度。
	具体过程如下：
	1、用栈维护当前待匹配的左括号的位置，同时用 start 记录一个新的可能合法的子串的起始位置，初始设为0。
	2、如果s[i] =='('，那么把i进栈。
	3、如果s[i] == ')',那么弹出栈顶元素 （代表栈顶的左括号匹配到了右括号），出栈后：
	如果栈为空，说明以当前右括号为右端点的合法括号序列的左端点为start，则更新答案 i - start + 1。
	如果栈不为空，说明以当前右括号为右端点的合法括号序列的左端点为栈顶元素的下一个元素，则更新答案i - st.top() 。
	4、遇到右括号)且当前栈为空，则当前的 start 开始的子串不再可能为合法子串了，下一个合法子串的起始位置可能是 i + 1，更新 start = i + 1。
	5、最后返回答案即可。

	实现细节： 栈保存的是下标。
	时间复杂度分析：每个位置遍历一次，最多进栈一次，故时间复杂度为 O(n)。
	 */
	int longestValidParentheses_1(string s) {
		stack<int> st;
		int maxRes = 0, start = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') st.push(i);    //左括号入栈
			else {
				if (!st.empty()) {
					st.pop();	//匹配成功
					if (st.empty()) maxRes = max(maxRes, i - start + 1);
					else maxRes = max(maxRes, i - st.top()); //i - st.top() + 1 - 1
				} else { // 栈为空说明组成不了有效括号，寻找下一个字串 更新起点
					start = i + 1;
				}
			}
		}
		return maxRes;
	}
};