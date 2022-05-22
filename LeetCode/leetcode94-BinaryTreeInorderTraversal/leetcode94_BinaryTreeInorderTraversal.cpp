// Created by 周子望 on 2021/11/16.

/*
 题目:二叉树的中序遍历
 给定一个二叉树的根节点 root ，返回它的 中序 遍历。

 思路与算法

有效 二叉搜索树定义如下：
 节点的左子树只包含 小于 当前节点的数。
 节点的右子树只包含 大于 当前节点的数。
 所有左子树和右子树自身必须也是二叉搜索树。

 首先我们需要了解什么是二叉树的中序遍历：
 按照访问左子树——根节点——右子树的方式遍历这棵树，而在访问左子树或者右子树的时候我们按照同样的方式遍历，直到遍历完整棵树。
 因此整个遍历过程天然具有递归的性质，我们可以直接用递归函数来模拟这一过程。

 定义 inorder(root) 表示当前遍历到 root 节点的答案，那么按照定义，我们只要递归调用 inorder(root.left) 来遍历 root 节点的左子树，
 然后将 root 节点的值加入答案，再递归调用inorder(root.right) 来遍历 root 节点的右子树即可，递归终止的条件为碰到空节点。
 */

#include "../../include.h"

// 非递归遍历
class Solution_Method {
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> stk;

		while (root != nullptr || !stk.empty()) {
			while (root != nullptr) {
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			stk.pop();
			res.push_back(root->val);
			root = root->right;
		}
		return res;
	}
};

// 递归遍历
class Solution {
private:
	void inorder(TreeNode* root, vector<int>& res) {
		if (!root) {
			return;
		}

		inorder(root->left, res);
		res.push_back(root->val);
		inorder(root->right, res);
	}

public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		return res;
	}
};

