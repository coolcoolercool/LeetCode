// Created by 周子望 on 2023/3/26.

/**
题目描述:

核心思想:
**/
#include <bits/stdc++.h>
#include "../../LeetCode/include.h"
using namespace std;

class Solution{
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> vec;
		while(head != nullptr) {
			vec.push_back(head->val);
			head = head->next;
		}

		reverse(vec.begin(), vec.end());
		return vec;
	}
};

int main() {
	Solution sol;
	vector<int> vec = {2, 3, 1, 0, 2, 5, 3};

	int res = 0;
	// res = sol.findRepeatNumber(vec);
	cout << res << endl;

	return 0;
}

class CQueue {
public:
	CQueue() {

	}

	void appendTail(int value) {

	}

	int deleteHead() {

	}
};