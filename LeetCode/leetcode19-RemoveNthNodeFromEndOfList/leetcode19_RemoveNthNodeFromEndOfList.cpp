#include "../../include.h"

/**
 * 题目描述:
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 *
 * 示例：
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 *
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 说明：
 * 给定的 n 保证是有效的。
 *
 * 核心思想:
 * 第一个指针从列表的开头向前移动 n+1 步，而第二个指针将从列表的开头出发。
 * 现在，这两个指针被第n个结点分开。
 * 我们通过同时移动两个指针向前来保持这个恒定的间隔，直到第一个指针到达最后一个结点。
 * 此时第二个指针将指向从最后一个结点数起的第 n 个结点。
 * 我们重新链接第二个指针所引用的结点的 next 指针指向该结点的下下个结点。
 *
 * 与寻找链表的倒数第k个节点很类似，这里需要寻找链表的倒数第k-1个节点,然后将(k-1)ThNode.next = (k-1)ThNode.next.next
 * 删除倒数第k个节点
 *
 * 对于链表题目，最好使用Java作答，因为不用管理废弃的节点
 */

class Solution {
public:
	/* 为什么要在head前创建一个新的节点，这样做可以避免讨论头结点被删除的情况，不管原来的head有没有被删除，直接返回dummy.next即可 */
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *fast = head;
		ListNode *slow = dummy;

		// 快指针 先走 n 步
		for (int i = 0; i < n; i++) fast = fast->next;

		// 等 快指针 达到末尾的 next，即为 nullptr 的时候，则 slow到了，倒数第 n-1 节点
		// 因为 slow = dummy，而dummy到head 还走了一步
		while (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}

		// 此时slow在第 倒数第n-1个节点上，而slow->next就是要删除的倒数第n个节点
		slow->next = slow->next->next;
		ListNode *ans = dummy->next;
		delete dummy;

		return ans;
	}
};