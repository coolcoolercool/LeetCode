// Created by 周子望 on 2023/2/21.

/**
题目描述:
https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/description/
合并两个有序链表

核心思想:
**/

#include "../../include.h"

class Solution {
public:
	ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;

		while(l1 != nullptr && l2 != nullptr) {
			if(l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			} else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		// 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
		if (l1 != nullptr) {
			cur->next = l1;
		} else if(l2 != nullptr) {
			cur->next = l2;
		}

		return dummy->next;
	}

	ListNode* mergeTwoList_DiGui(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) {
			return l2;
		} else if(l2 == nullptr) {
			return l1;
		} else if (l1->val < l2->val) {
			l1->next = mergeTwoList_DiGui(l1->next, l2);
		} else {
			l2->next = mergeTwoList_DiGui(l1, l2->next);
		}
	}

};