// Created by 周子望 on 2023/2/26.

/**
题目描述:
有序链表合并， 剑指offer简单题

核心思想:

题目来源:
国信证券 罗湖 230221 现场笔试题

**/

#include "../../../include.h"


class Solution{
public:
	ListNode* mergeSortedLinkedList(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		ListNode* dummy = new ListNode(1);
		ListNode* cur = dummy;

		while(l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			} else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}

		if (l1 != nullptr) {
			cur->next = l1;
		} else if(l2 != nullptr) {
			cur->next = l2;
		}

		return dummy->next;
	}
};
