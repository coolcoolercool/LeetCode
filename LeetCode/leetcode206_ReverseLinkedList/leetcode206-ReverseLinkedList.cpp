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
	ListNode* reverseList_0(ListNode* head) {
		if (!head || !head->next) return head;
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