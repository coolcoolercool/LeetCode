#include "../../include.h"

/*
题目:
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 */

class Solution {
public:
	/**
	   迭代解法
	   pre 和 cur 双指针
	   在遍历链表时，将当前节点的 next 指针改为指向前一个节点。由于节点没有引用其前一个节点，因此必须事先存储其前一个节点。在更改引用之前，还需要存储后一个节点。最后返回新的头引用。
	 */
	ListNode* reverseList(ListNode* head) {
		if(head == nullptr || head->next == nullptr) return head;
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while(cur != nullptr) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}

		return pre;
	}

	// 递归解法
	// https://leetcode.cn/problems/reverse-linked-list/solutions/36710/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/?orderBy=most_votes
	/*
	  递归的两个条件：
	  1. 终止条件是当前节点或者下一个节点为空节点
	  2. 在函数内部，改变节点的指向，也就是 head 的下一个节点指向 head 递归函数
	 */
	ListNode* reverseList_recurrence(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* newHead = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newHead;
	}

};

int main_insaasdsad () {
	Solution sol;
	vector<int> nums = {3,2,4};
	int target = 6;

	return 0;
};