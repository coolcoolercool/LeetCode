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
		ListNode* head = nullptr, *tail = nullptr;
		int add = 0;

		while(l1 != nullptr || l2 != nullptr) {
			int val1 = l1 != nullptr ? l1->val : 0;
			int val2 = l2 != nullptr ? l2->val : 0;

			int sum = val1 + val2 + add;
			if(head == nullptr) {
				head = tail = new ListNode(sum % 10);
			} else {
				tail->next = new ListNode(sum % 10);
				tail = tail->next;
			}
			add = sum / 10;
			if(l1 != nullptr) l1 = l1->next;
			if(l2 != nullptr) l2 = l2->next;
		}

		if (add > 0) tail->next = new ListNode(add);
		return head;
	}
};

