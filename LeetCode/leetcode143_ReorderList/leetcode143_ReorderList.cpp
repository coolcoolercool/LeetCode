// Created by rainyzwzhou on 2022/5/15.

/**
题目描述:
给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln

请将其重新排列后变为：
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

核心思想:
 注意到目标链表即为将原链表的左半端和反转后的右半端合并后的结果。

这样我们的任务即可划分为三步：
（1）找到原链表的中点（参考「876. 链表的中间结点」）。
	我们可以使用快慢指针来 O(N)O(N) 地找到链表的中间节点。

（2）将原链表的右半端反转（参考「206. 反转链表」）。
	我们可以使用迭代法实现链表的反转。

（3）将原链表的两端合并。
	因为两链表长度相差不超过 1，因此直接合并即可。

解法概述:
寻找链表中点 + 链表逆序 + 合并链表

这里的寻找中间节点
注意这里的中间节点
1->2->(3)->4
返回的是3
链表分为 1->2->3 和 4


1->2->(3)->4->5
返回的是3
链表分为1->2->3 和 4->5

**/

#include "../../include.h"
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void reorderList(ListNode *head) {
		if (head == nullptr) return;
		ListNode *mid = middleNode(head); // 找到中间节点
		ListNode *left = head;
		ListNode* right = mid->next;
		mid->next = nullptr;  // 将两个链表切断

		right = reverseList(right); // 将中间节点到链表尾部反转
		mergeList(left, right);
	}

	ListNode* middleNode(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* slow = dummy;
		ListNode* fast = dummy;
		while (fast != nullptr) {
			slow = slow->next;
			fast = fast->next;

			if(fast == nullptr) break;
			fast = fast->next;
		}
		delete dummy;
		return slow;
	}

	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode *cur = head;
		while (cur != nullptr) {
			ListNode *next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}

	// 注意这里可能回误导，其实可能会出现
	// l1 1->2->3 l2 4
	// 这种情况
	void mergeList(ListNode *l1, ListNode *l2) {
		ListNode *nextL1;
		ListNode *nextL2;
		while (l1 != nullptr && l2 != nullptr) {
			nextL1 = l1->next;
			nextL2 = l2->next;

			l1->next = l2;
			l1 = nextL1;

			l2->next = l1;
			l2 = nextL2;
		}
	}


public:
	// 利用线性表存储该链表，然后利用线性表可以下标访问的特点，直接按顺序访问指定元素，重建该链表即可。
	void reorderList_ver0(ListNode *head) {
		if (head == nullptr) {
			return;
		}
		vector<ListNode *> vec;
		ListNode *node = head;
		while (node != nullptr) {
			vec.emplace_back(node);
			node = node->next;
		}

		int left = 0, right = vec.size() - 1;
		while (left < right) {
			vec[left]->next = vec[right];
			left++;
			if (left == right) {
				break;
			}
			vec[right]->next = vec[left];
			right--;
		}
		vec[left]->next = nullptr;
	}
};

