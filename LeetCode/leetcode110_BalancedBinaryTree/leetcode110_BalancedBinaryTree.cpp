// Created by rainyzwzhou on 2022/6/3.

/**
题目描述:

核心思想:
必须先弄清楚一个概念,只要有某子树不平衡,则该树就不平衡


**/
#include "../../include.h"

class Solution {
public:
	bool isBalanced(TreeNode *root) {
		return recur(root) != -1;
	}

	int recur(TreeNode *root) {
		if (root == nullptr) return 0;

		int left = recur(root->left);  // 返回左(右)子树的深度,如果其深度为-1(默认不平衡),则全树不平衡
		if (left == -1) return -1;

		int right = recur(root->right);
		if (right == -1) return -1;

		return abs(left - right) < 2 ? max(left, right) + 1 : -1;
	}
};
