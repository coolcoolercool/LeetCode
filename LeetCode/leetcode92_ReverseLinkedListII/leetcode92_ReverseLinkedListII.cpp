// Created by rainyzwzhou on 2022/5/2.

/**
 题目:https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/fan-zhuan-lian-biao-ii-by-leetcode-solut-teyq/

思路想明白以后，编码不是一件很难的事情。这里要提醒大家的是，链接什么时候切断，什么时候补上去，先后顺序一定要想清楚，如果想不清楚，可以在纸上模拟，让思路清晰。
 */

#include "../../include.h"

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if(head == nullptr || head->next == nullptr) {
			return head;
		}

		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		ListNode* pre = dummy;
		// 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
		for(int i = 0; i < left - 1; i++) {
			pre = pre->next;
		}

		ListNode* cur = pre->next;
		ListNode* next;

		for(int i = 0; i < right - left; i++) {
			next = cur->next;  // 保存当前节点的下一个节点
			cur->next = next->next; //
			next->next = pre->next;
			pre->next = next;
		}

		return dummy->next;
	}






public:
	void reverseLinkedList(ListNode *head) {
		// 也可以使用递归反转一个链表
		ListNode *pre = nullptr;
		ListNode *cur = head;

		while (cur != nullptr) {
			ListNode *next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
	}

	// 中间需要反转的链表是 pre -> left ~ right ->cur
	// 处理完后 pre ->right ~ left ->cur
	ListNode *reverseBetween_recu(ListNode *head, int left, int right) {
		// 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
		ListNode *dummyNode = new ListNode(-1);
		dummyNode->next = head;

		ListNode *pre = dummyNode;
		// 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点 建议写在 for 循环里，语义清晰
		for (int i = 0; i < left - 1; i++) {
			pre = pre->next;
		}

		ListNode *rightNode = pre;
		for (int i = 0; i < right - left + 1; i++) { // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
			rightNode = rightNode->next;
		}

		ListNode *leftNode = pre->next; // 第 3 步：切断出一个子链表（截取链表）
		ListNode *cur = rightNode->next;

		pre->next = nullptr; // 注意：切断链接
		rightNode->next = nullptr;

		reverseLinkedList(leftNode); // 第 4 步：同第 206 题，反转链表的子区间

		// 第 5 步：接回到原来的链表中
		pre->next = rightNode;  // pre->next 从left到right了
		leftNode->next = cur;   //
		return dummyNode->next;
	}
};