// Created by rainyzwzhou on 2022/5/9.

/**
 */

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
	// 归并排序
public:
	ListNode* merge(ListNode *head1, ListNode *head2) {
		ListNode* dummy = new ListNode(0);
		ListNode* left = head1, * right = head2, *curNode = dummy;
		while(left != nullptr && right != nullptr) {
			if(left->val < right->val) {
				curNode->next = left;
				left = left->next;
			} else {
				curNode->next = right;
				right = right->next;
			}
			curNode = curNode->next;
		}

		if(left != nullptr) curNode->next = left;
		if(right != nullptr) curNode->next = right;

		return dummy->next;
	}

	//快慢指针分割链表函数
	ListNode *mergeSort(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return head;        //如果只有一个结点或者没有结点，直接返回

		ListNode *pre = nullptr; // 慢指针的前驱
		ListNode *slow = head; // 慢指针，每次走一步
		ListNode *fast = head; // 快指针，每次走两步

		while (fast != nullptr) { // 这种写法，其实pre才是mid节点，slow是mid的下一个节点，注意这里fast的判断是在移动节点后，才判断的，所以会多走一步
			pre = slow;
			slow = slow->next;
			fast = fast->next;
			if (fast != nullptr) fast = fast->next;
		}
		// 此时slow指针指向中间结点，用pre指针把链表从中间断开,分为[head,pre],[slow,fast]两段 {left, mid} {mid + 1, right}
		pre->next = nullptr;
		ListNode *L1 = mergeSort(head); //左边
		ListNode *L2 = mergeSort(slow); //右边
		return merge(L1, L2); //对两边进行归并
	}

	ListNode* sortList(ListNode *head) { // 第一种归并排序
		return mergeSort(head);
	}

public:
	// 快速排序
	ListNode* sortList_quickSort(ListNode* head) {
		if(!head || !head->next) return head;

		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		quicksort(dummy, nullptr);
		head = dummy->next;
		delete dummy;
		return head;
	}

	void quicksort(ListNode *head, ListNode *tail){
		if(head->next == tail) return;

		ListNode *p = head->next, *q = p->next, *pre = p;
		while(q != tail){
			if(q->val < p->val){
				pre->next = q->next;
				q->next = head->next;
				head->next = q;
				q = pre->next;
			}else{
				pre = pre->next;
				q = q->next;
			}
		}
		quicksort(head, p);
		quicksort(p, tail);
	}
};





