// Created by 周子望 on 2021/11/19

/*
 题目: 对称二叉树
 给定一个二叉树，检查它是否是镜像对称的。

 核心思想:
 如果同时满足下面的条件，两个树互为镜像：
(1)它们的两个根结点具有相同的值
(2)每个树的右子树都与另一个树的左子树镜像对称

 我们可以实现这样一个递归函数，通过「同步移动」两个指针的方法来遍历这棵树，p 指针和 q 指针一开始都指向这棵树的根，随后 p 右移时，q 左移，p 左移时，q 右移。
 每次检查当前 p 和 q 节点的值是否相等，如果相等再判断左右子树是否对称。
 */
#include "../../include.h"

class Solution {
	// 迭代版本
public:
	bool check(TreeNode* head1, TreeNode* head2){
		queue<TreeNode*> qe;
		qe.push(head1);
		qe.push(head2);

		while(!qe.empty()) {
			TreeNode* left = qe.front(); qe.pop();
			TreeNode* right = qe.front(); qe.pop();

			if(left == nullptr && right == nullptr) continue;
			if(!(left != nullptr && right != nullptr)) return false;
			if(left->val != right->val) return false;

			qe.push(left->left);
			qe.push(right->right);

			qe.push(left->right);
			qe.push(right->left);
		}
		return true;
	}

	bool isSymmetric(TreeNode* root) {
		if(root == nullptr) {
			return true;
		}

		return check(root->left, root->right);
	}

	// 递归版本
public:
	bool help (TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr) return true;
		if (left == nullptr || right == nullptr) return false;
		if (left->val != right->val) {  // 此时是left 和 right都不是 null
			return false;
		}

		return help(left->left, right->right) && check(left->right, right->left);
	}

	bool isSymmetric_recu(TreeNode* root) {
		if(root == nullptr) {
			return true;
		}
		return help(root->left, root->right);
	}
};

int mainom98jn () {
	Solution sol;
	bool res = false;

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);

	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);

	res = sol.isSymmetric(root);
	print_bool(res);

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);

	root->left->left = nullptr;
	root->left->right = new TreeNode(3);

	root->right->left = nullptr;
	root->right->right = new TreeNode(3);

	res = sol.isSymmetric(root);
	print_bool(res);

	return 0;
}