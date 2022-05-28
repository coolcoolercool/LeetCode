//
// Created by rainyzwzhou on 2022/5/1.
//

/**
题目:
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
*/

#include "../../include.h"

class Solution {
public:
	struct Comp {
		bool operator()(const ListNode *l1, const ListNode *l2) {
			return l1->val > l2->val;
		}
	};

	ListNode *mergeKLists(vector<ListNode *> &lists) {
		// priority_queue 模板有 3 个参数，其中两个有默认的参数；第一个参数是存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象
		priority_queue<ListNode *, vector<ListNode *>, Comp> pQueue;
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i]) { // 防止有的链表一开始就是 nullptr
				pQueue.push(lists[i]);
			}
		}

		ListNode *dummy = new ListNode();
		ListNode *cur = dummy;
		while (!pQueue.empty()) {
			ListNode *temp = pQueue.top();
			pQueue.pop();
			if (temp->next != nullptr) {
				pQueue.push(temp->next);
			}

			cur->next = temp;
			cur = cur->next;
		}
		return dummy->next;
	}
};