// Created by rainyzwzhou on 2022/5/17.

/**
题目描述:

核心思想:
**/

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if(head == nullptr || head->next == nullptr) return head;
		ListNode* oddHead = head;
		ListNode* evenHead = head->next;

		ListNode* oddTail = oddHead;
		ListNode* evenTail = evenHead;

		while(evenTail != nullptr && evenTail->next != nullptr) { //偶数指针不为空 继续循环
			oddTail->next = evenTail->next; //奇数指针指向偶数指针的next
			oddTail = oddTail->next; //移动奇数指针
			evenTail->next = oddTail->next;
			evenTail = evenTail->next; ;//移动偶数指针
		}

		// 当执行完终止条件，oddTail不为null，oddTail->next为null
		oddTail->next = evenHead; //奇数指针结尾连接上偶数指针的开始，奇偶链表连接成一个链表
		return oddHead;
	}
};