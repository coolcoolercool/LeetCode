//
// Created by rainyzwzhou on 2022/5/5.
//

/**
* 题目: 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
*/

#include "../../include.h"

class Solution {
	/**
	 * 递归前序遍历
	 */
public:
	TreeNode* invertTree(TreeNode *root) {
		//递归函数的终止条件，节点为空时返回
		if (root == nullptr) {
			return root;
		}
		//下面三句是将当前节点的左右子树交换
		TreeNode* tmpRight = root->right;
		root->right = root->left;
		root->left = tmpRight;
		//递归交换当前节点的 左子树
		invertTree(root->left);
		//递归交换当前节点的 右子树
		invertTree(root->right);
		//函数返回时就表示当前这个节点，以及它的左右子树
		//都已经交换完了
		return root;
	}

	TreeNode* invertTree_level(TreeNode* root) {
		queue<TreeNode*> levelQueue;
		if (root != NULL) levelQueue.push(root);

		while (!levelQueue.empty()) {
			int size = levelQueue.size();
			for (int i = 0; i < size; i++) {
				TreeNode* tempNode = levelQueue.front();
				levelQueue.pop();
				swap(tempNode->left, tempNode->right); // 交换左右节点

				if (tempNode->left) levelQueue.push(tempNode->left);
				if (tempNode->right) levelQueue.push(tempNode->right);
			}
		}
		return root;
	}

	void invert(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		TreeNode* tempNode = root->left;
		root->left = root->right;
		root->right = tempNode;

		invert(root->left);
		invert(root->right);
	}

	TreeNode* invertTree_ziji(TreeNode *root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
			return root;
		}

		invert(root);

		return root;
	}


};