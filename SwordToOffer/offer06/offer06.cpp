// Created by 周子望 on 2022/12/4.

/**
题目描述:

核心思想:
**/

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> result;
		ListNode* pre = head, *cur = nullptr;
		while(pre != nullptr) {
			ListNode * temp = pre -> next;  //临时变量
			pre -> next = cur;  //将当前节点指向cur
			cur = pre;  //cur移动到当前节点位置
			pre = temp; //pre移动到原链表的下一位
		}

		while(cur != nullptr) {
			result.push_back(cur->val);
			cur = cur->next;
		}
		return result;
	}

	vector<int> reversePrint_ver0(ListNode* head) {
		stack<int> innerStack;
		while(head != nullptr) {
			innerStack.push(head->val);
			head = head->next;
		}

		vector<int> result;
		while(!innerStack.empty()) {
			result.push_back(innerStack.top());
			innerStack.pop();
		}
		return result;
	}
};