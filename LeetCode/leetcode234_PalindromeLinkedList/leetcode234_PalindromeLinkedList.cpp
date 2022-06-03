// Created by rainyzwzhou on 2022/5/12.


#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
	/**
	避免使用 O(n) 额外空间的方法就是改变输入。
	我们可以将链表的后半部分反转（修改链表结构），然后将前半部分和后半部分进行比较。比较完成后我们应该将链表恢复原样。虽然不需要恢复也能通过测试用例，但是使用该函数的人通常不希望链表结构被更改。

	该方法虽然可以将空间复杂度降到 O(1)，但是在并发环境下，该方法也有缺点。在并发环境下，函数运行时需要锁定其他线程或进程对链表的访问，因为在函数执行过程中链表会被修改。

	算法
	整个流程可以分为以下五个步骤：
	(1)找到前半部分链表的尾节点。
	(2)反转后半部分链表。
	(3)判断是否回文。
	(4)恢复链表。
	(5)返回结果。
	 */

public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr) return true;

		// 找到前半部分链表的尾节点并反转后半部分链表
		ListNode* firstHalfEnd = endOfFirstHalf(head);
		ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

		// 判断是否回文
		ListNode* p1 = head;
		ListNode* p2 = secondHalfStart;
		bool result = true;
		while (result && p2 != nullptr) {
			if (p1->val != p2->val) {
				result = false;
			}
			p1 = p1->next;
			p2 = p2->next;
		}

		// 还原链表并返回结果
		firstHalfEnd->next = reverseList(secondHalfStart);
		return result;
	}

	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur != nullptr) {
			ListNode* nextTemp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nextTemp;
		}
		return pre;
	}

	ListNode* endOfFirstHalf(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next != nullptr && fast->next->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}

public:
	bool isPalindrome_0(ListNode* head) {
		if(head == nullptr || head->next == nullptr) return true;

		vector<int> arr;
		while(head != nullptr) {
			arr.push_back(head->val);
			head = head->next;
		}

		int left = 0, right = arr.size() - 1;
		while(left < right) {
			if(arr[left] != arr[right]) return false;
			left++;
			right--;
		}
		return true;
	}
};