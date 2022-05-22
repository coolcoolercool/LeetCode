// Created by rainyzwzhou on 2022/5/8.

/**
题目:https://leetcode-cn.com/problems/linked-list-cycle-ii/

核心思想:
根据：
select= 2s （快指针每次2步，路程刚好2倍）
select = s + nb (相遇时，刚好多走了n圈）

推出：s = nb
从head结点走到入环点需要走 ： a + nb， 而slow已经走了nb，那么slow再走a步就是入环点了。
如何知道slow刚好走了a步？ 从head开始，和slow指针一起走，相遇时刚好就是a步

 假设到环之前的距离为a，环的长度为b
	走a+nb步一定是在环入口
	第一次相遇时慢指针已经走了nb步

 此时再从起点开始走a步，就是环入口。新的指针和slow指针相遇就是环入口

 证明在slow入圈的第一圈，fast就会与slow相遇，最大的值，就是fast领先slow一个节点，即使如此slow跑一圈，fast会跑两圈，所以一定在第一圈就会相遇

 */

#include "../../include.h"

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		ListNode* slow = dummy;
		ListNode* fast = dummy;

		while(fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;

			if(fast == slow) { // 说明存在环，寻找环的入口
				ListNode* cur = dummy;
				while(cur != slow) {
					cur = cur->next;
					slow = slow->next;
				}
				return cur;
			}
		}

		return nullptr; // 如果fast和slow没有相遇，表示没有环，也就没有环的入口
	}
};