// Created by rainyzwzhou on 2022/5/1.

/**
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 */

#include "../../include.h"

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* dummy = new ListNode(0);
		ListNode* curNode = dummy;
		while(list1 != nullptr && list2 != nullptr) {
			if(list1->val < list2->val) {
				curNode->next = list1;
				list1 = list1->next;
			} else {
				curNode->next = list2;
				list2 = list2->next;
			}
			curNode = curNode->next;
		}

		if (list1 != nullptr) curNode->next = list1;
		if (list2 != nullptr) curNode->next = list2;
		return dummy->next;
	}

	// 进阶 合并两个有序链表并去重
	ListNode* mergeTwoLists_quchong(ListNode* list1, ListNode* list2) {
		ListNode* dummy = new ListNode(101);
		ListNode* cur = dummy;

		while(list1 != nullptr && list2 != nullptr) {
			if(list1->val < list2->val) {
				if(cur->val == list1->val) {
					list1 = list1->next;
					continue;
				}
				cur->next = list1;
				list1 = list1->next;
			} else {
				if(cur->val == list2->val) {
					list2 = list2->next;
					continue;
				}
				cur->next = list2;
				list2 = list2->next;
			}
			cur = cur->next;
		}

		if (list1 != nullptr) {
			while(list1 != nullptr && cur->val == list1->val) {
				list1 = list1->next;
			}
			cur->next = list1;  // 因为list1和list2本身也是有序的，所以只要判断当前节点值不一样，即可
		}

		if (list2 != nullptr) {
			while(list2 != nullptr && cur->val == list2->val) {
				list2 = list2->next;
			}
			cur->next = list2;
		}

		return dummy->next;
	}
};