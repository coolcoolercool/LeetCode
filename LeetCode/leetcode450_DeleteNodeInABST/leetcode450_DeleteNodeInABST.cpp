// Created by 周子望 on 2022/6/13.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/delete-node-in-a-bst/solution/450-shan-chu-er-cha-sou-suo-shu-zhong-de-jie-dia-6/

**/

#include "../../include.h"
using namespace std;

class Solution {
public:
	TreeNode *deleteNode(TreeNode *root, int key) {
		if (root == nullptr) return root;

		if (key < root->val) { // 当前节点值比key小，则需要删除当前节点的左子树中key对应的值，并保证二叉搜索树的性质不变
			root->left = deleteNode(root->left, key);
		} else if (key > root->val) { // 当前节点值比key大，则需要删除当前节点的右子树中key对应的值，并保证二叉搜索树的性质不变
			root->right = deleteNode(root->right, key);
		} else { // 当前节点等于key，则需要删除当前节点，并保证二叉搜索树的性质不变
			if (root->left == nullptr) return root->right; 		 // 当前节点没有左子树
			else if (root->right == nullptr) return root->left;  // 当前节点没有右子树
			else { 	// 当前节点既有左子树又有右子树
				TreeNode *cur = root->right;
				while (cur->left != nullptr) { 	// 找到当前节点右子树最左边的叶子结点
					cur = cur->left;
				}

				// 将root的左子树放到root的右子树的最下面的左叶子节点的左子树上
				cur->left = root->left;
				return root->right;
			}
		}
		return root;
	}
};
