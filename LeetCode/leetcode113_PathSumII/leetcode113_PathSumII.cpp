// Created by rainyzwzhou on 2022/5/28.

/**
题目描述:
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。


核心思想:
**/

#include "../../include.h"


class Solution {
	// 自己的写法，简单来说需要先处理下头结点，然后再处理其他子节点
public:
	vector<vector<int>> res;
	vector<int> oneRes;

	void help(TreeNode *root, int remain) {
		if (root == nullptr) return;

		if (root->left == nullptr && root->right == nullptr && remain == 0) {
			res.push_back(oneRes);
			return;
		}

		if (root->left != nullptr) {
			remain -= root->left->val;
			oneRes.push_back(root->left->val);
			help(root->left, remain);
			remain += root->left->val;
			oneRes.pop_back();
		}

		if (root->right != nullptr) {
			remain -= root->right->val;
			oneRes.push_back(root->right->val);
			help(root->right, remain);
			remain += root->right->val;
			oneRes.pop_back();
		}
	}

	vector<vector<int>> pathSum_0(TreeNode *root, int targetSum) {
		if (root == nullptr) return res;

		oneRes.push_back(root->val);
		help(root, targetSum - root->val);

		return res;
	}
};

class Solution_ver1 {
	// 这种写法，不需要预先处理头结点
public:
	vector<vector<int>> res;
	vector<int> oneRes;

	void help(TreeNode *root, int remain) {
		if (root == nullptr) return;

		if (root->left == nullptr && root->right == nullptr && remain - root->val == 0) {
			oneRes.push_back(root->val);
			res.push_back(oneRes);
			oneRes.pop_back();
			return;
		}

		if (root->left != nullptr) {
			oneRes.push_back(root->val);
			remain -= root->val;
			help(root->left, remain);
			remain += root->val;
			oneRes.pop_back();
		}

		if (root->right != nullptr) {
			oneRes.push_back(root->val);
			remain -= root->val;
			help(root->right, remain);
			remain += root->val;
			oneRes.pop_back();
		}
	}

	vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
		if (root == nullptr) return res;

		help(root, targetSum);

		return res;
	}
};