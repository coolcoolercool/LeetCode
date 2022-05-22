// Created by rainyzwzhou on 2022/5/21.

/**
题目描述:
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

核心思想:
**/

#include "../../include.h"


class Solution {
private:
	Node *pre, *head;
	void dfs(Node* cur) {
		if(cur == nullptr) return;
		dfs(cur->left);

		//pre用于记录双向链表中位于cur左侧的节点，即上一次迭代中的cur,当pre==null时，cur左侧没有节点,即此时cur为双向链表中的头
		if(pre != nullptr) {
			pre->right = cur;
		} else { // pre == nullptr  反之，pre!=null时，cur左侧存在节点pre，需要进行pre.right=cur的操作。
			head = cur;
		}

		cur->left = pre;
		pre = cur;

		dfs(cur->right); //全部迭代完成后，pre指向双向链表中的尾节点
	}

public:
	Node* treeToDoublyList(Node* root) {
		if(root == nullptr) return root;

		dfs(root);

		head->left = pre; //进行头节点和尾节点的相互指向，这两句的顺序也是可以颠倒的
		pre->right = head;
		return head;
	}

};