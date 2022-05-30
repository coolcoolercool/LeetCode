// Created by rainyzwzhou on 2022/5/28.

/**
题目描述:

核心思想:
**/

#include "../../include.h"

class Solution {
public:
	bool flag = false;

	void help(TreeNode *root, int remain) {
		if (root == nullptr) return;

		if (root->left == nullptr && root->right == nullptr && remain - root->val == 0) {
			flag = true;
			return;
		}

		if (root->left != nullptr) {
			help(root->left, remain - root->val);
		}
		if (root->right != nullptr) {
			help(root->right, remain - root->val);
		}

	}

	bool hasPathSum(TreeNode *root, int targetSum) {
		help(root, targetSum);

		return flag;
	}
};