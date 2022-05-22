// Created by rainyzwzhou on 2022/5/2.

#include "../../include.h"

class Solution {
	/**
	 * dummy -> 1 -> 2 -> 3 -> 4
	 */
public:
	ListNode* swapPairs_shulian(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		// one -> tow -> three -> three_next
		// one -> three -> tow -> three_next
		ListNode* one = dummy;
		while(one->next != nullptr && one->next->next != nullptr) {  // 注意这里是 next 和 next->next 非空
			ListNode* tow = one->next;  // 保存1
			ListNode* three = one->next->next; // 保存2

			one->next = three; // dummy -> 2
			tow->next = three->next; // 因为需要更新2的next为1，但是2的next是接下来需要处理的，需要放到 1的next后面。如果直接执行 2->1 就会造成 2的next丢了
			three->next = tow; // 实现 2 -> 1

			one = tow; // 此时来到下一个要处理的节点 3 之前的节点
		}

		return dummy->next;
	}

	// 最简单版本，将链表分为四个部分 1 2 3 3next
	ListNode* swapPairs(ListNode* head) {
		// 1 -> 2 -> 3 -> 3next
		// 1 -> 3 -> 2 -> 3next

		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* one = dummy;
		while(one->next != nullptr && one->next->next != nullptr) {
			ListNode* two = one->next;
			ListNode* three = one->next->next;
			ListNode* threeNext = three->next;

			one->next = three;
			one->next->next = two;
			two->next = threeNext;

			one = two;
		}

		return dummy->next;
	}
};