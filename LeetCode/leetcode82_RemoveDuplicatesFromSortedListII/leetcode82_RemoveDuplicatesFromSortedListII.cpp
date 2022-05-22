// Created by rainyzwzhou on 2022/5/17.

/**
题目描述:
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

 题目中要求，将重复的节点删除，而不是只保留一个

核心思想:
**/

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return head;

		ListNode *dummy = new ListNode(-101);
		dummy->next = head;
		ListNode *pre = dummy;
		ListNode *cur = head;

		while (cur != nullptr && cur->next != nullptr) {
			if (cur->val == cur->next->val) {
				int dupValue = cur->val;  // 这里保存了存在重复节点的值，可以很方便遍历所有等于这个值的节点
				while (cur != nullptr && cur->val == dupValue) { // 遍历直到 cur->dupValue != dupValue
					cur = cur->next;
				}
				pre->next = cur; // 将重复的节点全部删除
			} else { // 注意正常情况下，pre的处理差异
				pre = cur;
				cur = cur->next;
			}
		}
		return dummy->next;
	}
};