// Created by 周子望 on 2023/3/26.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
#include "../../include.h"

using namespace std;

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if(head == nullptr) return head;

		ListNode* pre = nullptr;
		ListNode* cur = head;
		while(cur != nullptr) {
			ListNode* temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}

		return pre;
	}
};