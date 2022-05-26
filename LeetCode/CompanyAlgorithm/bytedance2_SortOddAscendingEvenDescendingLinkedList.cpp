// Created by rainyzwzhou on 2022/5/16.

/**
题目描述:
给定一个奇数位升序，偶数位降序的链表，返回对其排序后的链表。
题面解释：例如链表 1->3->2->2->3->1 是奇数位升序偶数位降序的链表，而 1->3->2->2->3->2 则不符合题目要求。
数据范围：链表中元素个数满足 1≤n≤10000，链表中的元素大小满足 1≤val≤100000

https://www.nowcoder.com/questionTerminal/3a188e9c06ce4844b031713b82784a2a

核心思想:
给定的链表 是奇数的链表节点是升序有序，偶数链表节点是降序有序。
 (1)奇数节点链表和偶数节点链表拆开，此时奇数链表是升序有序，偶数链表是降序有序
 (2)将偶数链表反转，此时偶数链表也是降序有序
 (3)将奇数链表和偶数链表合并，即两个有序链表合并成一个有序链表
step1: leetcode328 奇偶链表，去掉两链表合并的步骤；
step2: leetcode206 反转链表；
step3: leetcode21  合并两个有序链表；

**/

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	ListNode* sortLinkedList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;

		// 先把奇数位链表 和 偶数位链表拆开
		ListNode *oddHead = head;
		ListNode *evenHead = head->next;

		ListNode *oddCur = oddHead;
		ListNode *evenCur = evenHead;

		while (evenCur != nullptr && evenCur->next != nullptr) { //偶数指针不为空 继续循环
			oddCur->next = evenCur->next; //奇数指针指向偶数指针的next
			oddCur = oddCur->next; //移动奇数指针
			evenCur->next = oddCur->next;
			evenCur = evenCur->next;;//移动偶数指针
		}
		oddCur->next = nullptr;

		// 然后把偶数位链表逆序
		evenHead = reverseList(evenHead);
		// 最后把两个升序的链表归并
		return mergeList(oddHead, evenHead);
	}

	// 反转链表
	ListNode* reverseList(ListNode* head) {
		if(head == nullptr) return head;
		ListNode* prev = nullptr;
		ListNode* cur = head;
		while(cur != nullptr){
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}

	// 合并两个有序链表
	ListNode* mergeList(ListNode* head1, ListNode* head2) {
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		while(head1 != nullptr && head2 != nullptr){
			if(head1->val <= head2->val){
				cur->next = head1;
				head1 = head1->next;
			}else{
				cur->next = head2;
				head2 = head2->next;
			}
			cur = cur->next;
		}
		if(head1 != nullptr)  cur->next = head1;
		else  cur->next = head2;
		return dummy->next;
	}
};
