//
// Created by rainyzwzhou on 2022/4/26.
//

/**
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：
	void push(int x) 将元素 x 推到队列的末尾
	int pop() 从队列的开头移除并返回元素
	int peek() 返回队列开头的元素
	boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：

你 只能 使用标准的栈操作 —— 也就是只有push to top,peek/pop from top,size, 和is empty操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks
 */

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
	stack<int> stackLeft;
	stack<int> stackRight;

public:
	MyQueue() {

	}

	void push(int x) {
		stackLeft.push(x);
	}

	int pop() {
		if (stackRight.empty() && stackLeft.empty()) {
			// 异常
			return -1;
		}

		if(stackRight.empty() && !stackLeft.empty()) {
			while(!stackLeft.empty()){
				int val = stackLeft.top();
				stackLeft.pop();
				stackRight.push(val);
			}
		}

		int val = stackRight.top();
		stackRight.pop();
		return val;
	}

	int peek() {
		if(stackRight.empty() && !stackLeft.empty()) {
			while(!stackLeft.empty()){
				int val = stackLeft.top();
				stackLeft.pop();
				stackRight.push(val);
			}
		}

		return stackRight.top();
	}

	bool empty() {
		if(stackLeft.empty() && stackRight.empty()) {
			return true;
		}
		return false;
	}
};

