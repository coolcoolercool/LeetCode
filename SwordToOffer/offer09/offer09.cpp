// Created by 周子望 on 2022/12/4.

/**
题目描述:

核心思想:
**/

#include<bits/stdc++.h>
using namespace std;

class CQueue {
public:
	CQueue() {
		size = 0;
	}

	void appendTail(int value) {
		first.push(value);
		size++;
	}

	int deleteHead() {
		int res = -1;
		if (first.empty() && second.empty()) {
			return res;
		}
		if(second.empty()) {
			while(!first.empty()) {
				second.push(first.top());
				first.pop();
			}
		}
		res = second.top();
		second.pop();
		size--;
		return res;
	}

private:
	int size;
	stack<int> first;
	stack<int> second;
};