// Created by 周子望 on 2021/11/17.

/*
 题目:验证二叉搜索树

给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

核心思想:
 中序遍历，同时维护一个左边的结点，用于判断当前结点是否大于它
 */

#include <climits>
#include "../../include.h"

class Solution {
	// 迭代
public:
	// predecessor 前继  successor 后继
	bool isValidBST(TreeNode* root) {
		stack<TreeNode *> stack;
		TreeNode* pre = nullptr;
		while (!stack.empty() || root != nullptr) {
			while (root != nullptr) {
				stack.push(root);
				root = root ->left;
			}

			root = stack.top();
			stack.pop();

			// 如果中序遍历得到的节点的值，小于等于前一个 predecessor，说明不是二叉搜索树
			if (pre != nullptr && pre->val >= root->val) {
				return false;
			} else { // 这里是 pre == nullptr || pre->val < root->val
				pre = root;
			}

			root = root->right;
		}
		return true;
	}

public:
	/**
	如果该二叉树的左子树不为空，则左子树上所有节点的值均小于它的根节点的值； 若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值；它的左右子树也为二叉搜索树

	 递归
	 */
	bool helper(TreeNode* root, long long left, long long right) {
		if (root == nullptr) return true;

		if (root->val <= left || root->val >= right) return false;

		return helper(root->left, left, root->val) && helper(root->right, root->val, right);
	}

	bool isValidBST_recu(TreeNode* root) {
		return helper(root, LLONG_MIN, LLONG_MAX);
	}
};
