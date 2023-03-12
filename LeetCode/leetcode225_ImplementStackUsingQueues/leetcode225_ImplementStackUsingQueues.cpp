// Created by 周子望 on 2023/2/19.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class MyStack{
public:
	queue<int> queue1;
	queue<int> queue2;

	MyStack(){};

	void push(int x) {
		queue2.push(x);
		while(!queue1.empty()) {
			queue2.push(queue1.front());
			queue1.pop();
		}
		swap(queue1, queue2);
	}

	int pop() {
		int val = queue1.front();
		queue1.pop();
		return val;
	}

	int top() {
		int val = queue1.front();
		return val;
	}

	bool empty() {
		return queue1.empty();
	}
};