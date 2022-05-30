//
// Created by rainyzwzhou on 2022/5/8.
//

/**
 *
 */

#include "../../include.h"

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		ListNode* slow = dummy;
		ListNode* fast = dummy;

		while(fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow) return true;
		}
		return false;
	}
};