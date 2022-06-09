// Created by rainyzwzhou on 2022/6/8.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/copy-list-with-random-pointer/solution/fu-zhi-dai-sui-ji-zhi-zhen-de-lian-biao-c2nvs/

**/

using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node *random;

	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

class Solution {
public:
	Node *copyRandomList(Node *head) {
		for (Node *cur = head; cur != nullptr; cur = cur->next->next) {  //复制每个节点，并将原链表和复制链表连在一起。
			auto copyNode = new Node(cur->val);
			copyNode->next = cur->next;
			cur->next = copyNode;
		}

		for (Node *cur = head; cur != nullptr; cur = cur->next->next) { //复制random指针
			if (cur->random != nullptr)
				cur->next->random = cur->random->next; // 这里的next就是新的节点了，而不是 newCur->next->random = newCur->random
		}

		Node *dummy = new Node(0);
		Node *newCur = dummy;
		for (Node *p = head; p != nullptr; p = p->next) { //拆分两个链表，并复原原链表
			auto temp = p->next;

			newCur->next = temp;
			newCur = newCur->next;

			p->next = temp->next; // 这里将原来新增复制节点从原链表中删除
		}

		return dummy->next;
	}

	Node *copyRandomList_ver0(Node *head) {
		Node *cur = head;
		while (cur != nullptr) {
			Node *copy = new Node(cur->val);
			copy->next = cur->next;
			cur->next = copy;

			cur = cur->next->next;
		}

		cur = head;
		while (cur != nullptr) {
			if (cur->random != nullptr) {
				cur->next->random = cur->random->next;
			}
			cur = cur->next->next;
		}

		Node *dummy = new Node(0);
		Node *newCur = dummy;
		cur = head;
		while (cur != nullptr) {
			Node *temp = cur->next;
			newCur->next = temp;
			newCur = newCur->next;

			cur->next = temp->next;
			cur = cur->next;
		}

		return dummy->next;
	}
};


class Solution_test {
public:
	Node *copyRandomList(Node *head) {
		// 复制节点 复制随机指针， 拆分链表
		Node *cur = head;
		while (cur != nullptr) {
			Node *copy = new Node(cur->val);
			copy->next = cur->next;
			cur->next = copy;

			cur = cur->next->next;
		}

		cur = head;
		while (cur != nullptr) {
			if (cur->random != nullptr) {
				cur->next->random = cur->random->next;
			}
			cur = cur->next->next;
		}

		Node *dummy = new Node(0);
		Node *newCur = dummy;
		cur = head;

		while (cur != nullptr) {
			Node *temp = cur->next;

			newCur->next = temp;
			newCur = newCur->next;

			cur->next = temp->next;
			cur = cur->next;
		}

		return dummy->next;
	}
};

















