// Created by rainyzwzhou on 2022/4/26.

/**
 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 二叉树的层次遍历
 */

#include "../../include.h"

class Solution {
	// 非递归，使用队列
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr) return res;

		queue<TreeNode *> lQueue;
		lQueue.push(root);
		while (!lQueue.empty()) {
			vector<int> oneLevel;
			int size = lQueue.size();  // 这里必须事前取的本层节点的数目，因为queueLevel的size会变化

			for (int i = 0; i < size; i++) {
				TreeNode *node = lQueue.front();
				lQueue.pop();
				oneLevel.push_back(node->val);

				if (node->left != nullptr) lQueue.push(node->left);
				if (node->right != nullptr) lQueue.push(node->right);
			}
			res.push_back(oneLevel);
		}

		return res;
	}

	// 递归写法
public:
	vector<vector<int>> res;

	void level(TreeNode *root, int levelCnt) {
		if (root == nullptr) return;

		if (levelCnt >= res.size()) {
			res.push_back(vector<int>());
		}

		res[levelCnt].push_back(root->val);

		level(root->left, levelCnt + 1);
		level(root->right, levelCnt + 1);
	}

	vector<vector<int>> levelOrder_0(TreeNode *root) {
		level(root, 0);
		return res;
	}
};