// Created by rainyzwzhou on 2022/5/10.

/**
题目:
 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
 */

#include "../../include.h"
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(head == nullptr || head->next == nullptr) return head;

		ListNode* dummy = new ListNode(101);
		dummy->next = head;
		ListNode* cur = dummy;

		while(cur != nullptr && cur->next != nullptr) {
			if (cur->val == cur->next->val) {
				cur->next = cur->next->next;
			} else {
				cur = cur->next;
			}
		}

		return dummy->next;
	}

	ListNode* deleteDuplicates_1(ListNode* head) {
		if(head == nullptr || head->next == nullptr) return head;

		ListNode* dummy = new ListNode(101);
		dummy->next = head;
		ListNode* curNode = dummy;

		while(curNode->next != nullptr && curNode->next->next != nullptr) {
			ListNode* nextNext = curNode->next->next;
			ListNode* next = curNode->next;

			if(nextNext->val == next->val) {
				curNode->next = nextNext; // 注意这一步，不能让 curNode = curNode->next，因为可能当前节点与next还是相同，比如 1 -> 1 -> 1这种情况
			} else {
				curNode = next;
			}
		}

		return dummy->next;
	}
};