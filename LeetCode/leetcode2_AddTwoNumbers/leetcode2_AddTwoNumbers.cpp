#include "../../include.h"

/*
题目:
给你两个非空 的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

链接：https://leetcode-cn.com/problems/add-two-numbers
 */

class LeetCode2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		ListNode *dummy = new ListNode(0);
		ListNode *cur = dummy;
		int add = 0;

		while (l1 != nullptr || l2 != nullptr || add != 0) {
			int val1 = l1 == nullptr ? 0 : l1->val;
			int val2 = l2 == nullptr ? 0 : l2->val;

			int sum = val1 + val2 + add;
			add = sum / 10;
			sum = sum % 10;

			cur->next = new ListNode(sum);

			cur = cur->next;
			if (l1 != nullptr) l1 = l1->next; // 注意这里非空，才会到下一个
			if (l2 != nullptr) l2 = l2->next;
		}

		return dummy->next;
	}
};

