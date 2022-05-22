// Created by rainyzwzhou on 2022/5/21.

/**
题目描述:
https://leetcode.cn/problems/remove-linked-list-elements/
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

核心思想:
**/

#include "../../include.h"

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		ListNode* pre = dummy;
		ListNode* cur = head;
		while(cur != nullptr) {
			if(cur->val == val) {
				while(cur != nullptr && cur->val == val) {
					cur = cur->next;
				}
				pre->next = cur;
			} else {
				pre = cur;
				cur = cur->next;
			}
		}

		return dummy->next;
	}
};
