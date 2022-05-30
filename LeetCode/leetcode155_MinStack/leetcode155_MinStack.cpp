// Created by rainyzwzhou on 2022/5/10.

/**
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * 不用辅助空间的方法，很炫酷
 * 在元素中添加了，pair的中，secondkey为当前元素的最小值
 */
class MinStack_NoSpace {
private:
	stack<pair<int, int>> innerStack; // {val, minVal}
public:
	MinStack_NoSpace() {
	}

	void push(int val) {
		if (innerStack.size() == 0) {
			innerStack.push({val, val});
		} else {
			innerStack.push({val, min(val, innerStack.top().second)});
		}
	}

	void pop() {
		innerStack.pop();
	}

	int top() {
		return innerStack.top().first;
	}

	int getMin() {
		return innerStack.top().second;
	}
};

/**
 * 使用辅助两个栈的做法
 * 核心思想:
我们只需要设计一个数据结构，使得每个元素 a 与其相应的最小值 m 时刻保持一一对应。因此我们可以使用一个辅助栈，与元素栈同步插入与删除，用于存储与每个元素对应的最小值。
当一个元素要入栈时，我们取当前辅助栈的栈顶存储的最小值，与当前元素比较得出最小值，将这个最小值插入辅助栈中；
当一个元素要出栈时，我们把辅助栈的栈顶元素也一并弹出；
在任意一个时刻，栈内元素的最小值就存储在辅助栈的栈顶元素中。

 */
class MinStack {
private:
	stack<int> dataStack;
	stack<int> minStack;

public:
	MinStack() {
		minStack.push(INT_MAX);
	}

	void push(int val) {
		dataStack.push(val);
		minStack.push( min(minStack.top(), val) );
	}

	void pop() {
		dataStack.pop();
		minStack.pop();
	}

	int top() {
		return dataStack.top();
	}

	int getMin() {
		return minStack.top();
	}
};

