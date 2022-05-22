// Created by rainyzwzhou on 2022/5/14.

/**
题目描述:
给定一个整数数组temperatures，表示每天的温度，返回一个数组answer，其中answer[i]是指在第 i 天之后，才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。

核心思想:
 判断是否需要使用单调栈，如果需要找到左边或者右边第一个比当前位置的数大或者小，则可以考虑使用单调栈；单调栈的题目如矩形米面积等等
 https://leetcode.cn/problems/daily-temperatures/solution/leetcode-tu-jie-739mei-ri-wen-du-by-misterbooo/

遍历整个数组，如果栈不空，且当前数字大于栈顶元素，那么如果直接入栈的话就不是 递减栈 ，所以需要取出栈顶元素，由于当前数字大于栈顶元素的数字，而且一定是第一个大于栈顶元素的数，直接求出下标差就是二者的距离。
继续看新的栈顶元素，直到当前数字小于等于栈顶元素停止，然后将数字入栈，这样就可以一直保持递减栈，且每个数字和第一个大于它的数的距离也可以算出来。

**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	// 需要找到左边或者右边第一个比当前位置的数大或者小，则可以考虑使用单调栈
public:
	vector<int> dailyTemperatures(vector<int> &temperatures) {
		int size = temperatures.size();
		vector<int> res(size);
		stack<int> st;  // 栈中放的是 温度值对应的索引
		for (int i = 0; i < temperatures.size(); ++i) {
			while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
				int highIndex = st.top();
				st.pop();
				res[highIndex] = i - highIndex; // 过了 temp[i]比temp[highIndex]高，计算相差的天数
			}
			st.push(i);
		}
		return res;
	}


	// 两次遍历，超时
	vector<int> dailyTemperatures_0(vector<int>& temperatures) {
		vector<int> res(temperatures.size());
		if(temperatures.size() < 2) return res;

		for(int i = 0; i < temperatures.size(); i++) {
			for(int j = i + 1; j < temperatures.size(); j++) {
				if(temperatures[j] > temperatures[i]) {
					res[i] = j - i;
					break;
				};
			}
		}

		return res;
	}
};