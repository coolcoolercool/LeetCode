// Created by rainyzwzhou on 2022/5/14.

/**
题目描述:

核心思想:
**/

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	// 翻转一个子链表，并且返回新的头与尾
	pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (pre != tail) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return {tail, head};
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = head;

		while (cur != nullptr) {
			ListNode* tail = pre;
			// 查看剩余部分长度是否大于等于 k
			for (int i = 0; i < k; ++i) {
				tail = tail->next;
				if (tail == nullptr) {  // 长度不足以k
					return dummy->next;
				}
			}

			ListNode* nex = tail->next;  // 保存下一个k个链表一组的头结点

			pair<ListNode*, ListNode*> res = myReverse(cur, tail);
			cur = res.first;  // res {tail, head}
			tail = res.second;

			// 把子链表重新接回原链表
			pre->next = cur;
			tail->next = nex;
			pre = tail;
			cur = tail->next;
		}

		return dummy->next;
	}
};
