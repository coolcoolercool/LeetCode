// Created by rainyzwzhou on 2022/5/30.

/**
题目描述:

核心思想:
**/

#include "../../include.h"

class Solution {
public:
	ListNode *getKthFromEnd(ListNode *head, int k) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;

		ListNode *fast = dummy;
		ListNode *slow = dummy;

		for (int i = 0; i < k; i++) {
			fast = fast->next;
		}

		while (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}

		return slow;
	}
};
