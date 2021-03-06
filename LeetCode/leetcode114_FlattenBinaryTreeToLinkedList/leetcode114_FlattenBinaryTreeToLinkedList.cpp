// Created by rainyzwzhou on 2022/5/30.

/**
题目描述:
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。


核心思想:
https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solution/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/

初步的操作思路:
(1)将左子树插入到右子树的地方
(2)将原来的右子树接到左子树的最右边节点
(3)考虑新的右子树的根节点，一直重复上边的过程，直到新的右子树为 null
**/

#include "../../include.h"

class Solution {
	// 寻找前驱节点
public:
	void flatten(TreeNode *root) {
		TreeNode *cur = root;
		while (cur != nullptr) {
			if (cur->left != nullptr) {
				TreeNode *cueLeft = cur->left; // 找左子树最右边的节点
				TreeNode *pre = cueLeft;
				while (pre->right != nullptr) {
					pre = pre->right;
				}
				pre->right = cur->right;  //将原来的右子树接到左子树的最右边节点
				cur->left = nullptr;
				cur->right = cueLeft;  // 将左子树插入到右子树的地方
			}
			cur = cur->right;   //左子树为 null，直接考虑下一个节点
		}
	}

	// 使用迭代来处理
	void flatten_0(TreeNode *root) {
		if (root == nullptr) return;
		stack<TreeNode *> st;
		st.push(root);
		TreeNode *pre = nullptr;

		while (!st.empty()) {
			TreeNode *cur = st.top();
			if (pre != nullptr) {
				pre->right = cur;
				pre->left = nullptr;
			};

			if (cur->right != nullptr) {
				st.push(cur->right);
			}
			if (cur->left != nullptr) {
				st.push(cur->left);
			}
			pre = cur;
		}
	}

	// 后续遍历
	void flatten_ver1(TreeNode *root) {
		if (root == nullptr) {
			return;
		}
		flatten(root->left);        //将根节点的左子树变成链表
		flatten(root->right);        //将根节点的右子树变成链表

		TreeNode *tempRight = root->right;
		root->right = root->left;        //把树的右边换成左边的链表
		root->left = nullptr;            //记得要将左边置空
		while (root->right != nullptr) root = root->right;        //找到树的最右边的节点
		root->right = tempRight;                //把右边的链表接到刚才树的最右边的节点
	}

};
