// Created by rainyzwzhou on 2022/5/27.

/**
题目描述:
https://leetcode.cn/problems/add-two-numbers-ii/

核心思想:
**/

#include "../../include.h"

using namespace std;

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		stack<int> st1, st2;
		while (l1 != nullptr) {
			st1.push(l1->val);
			l1 = l1->next;
		}
		while (l2 != nullptr) {
			st2.push(l2->val);
			l2 = l2->next;
		}

		int carry = 0;
		ListNode *res = nullptr;
		while (!st1.empty() || !st2.empty() || carry != 0) {
			int val1 = st1.empty() ? 0 : st1.top();
			int val2 = st2.empty() ? 0 : st2.top();
			if (!st1.empty()) st1.pop();
			if (!st2.empty()) st2.pop();

			int val = val1 + val2 + carry;
			carry = val / 10;
			val %= 10;

			ListNode *cur = new ListNode(val);
			cur->next = res;
			res = cur;
		}

		return res;
	}
};
