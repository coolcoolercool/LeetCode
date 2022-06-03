// Created by rainyzwzhou on 2022/5/15.

/**
题目描述:
给定一个头结点为 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。

核心思想:
注意这里的中间节点
1->2->3->(4)->5->6
返回的是4

1->2->(3)->4->5
返回的是3

**/

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* slow = dummy;
		ListNode* fast = dummy;
		while (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;

			if (fast == nullptr) break;
			fast = fast->next;
		}

		return slow;
	}

	ListNode *middleNode_0(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
		}

		return slow;
	}
};