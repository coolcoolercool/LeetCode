// Created by 周子望 on 2021/11/22.


#include "../../include.h"

class Solution {
	/* 二叉树的前序遍历：按照访问根节点——左子树——右子树的方式遍历这棵树，而在访问左子树或者右子树的时候，我们按照同样的方式遍历，直到遍历完整棵树。 */
	/* 递归实现 */
private:
	void preorder (TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}

		res.push_back(root->val);
		preorder(root->left, res);
		preorder(root->right, res);
	}

public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorder(root, res);
		return res;
	}

	/* 迭代实现 */
public:
	vector<int> preorderTraversal_Iterate(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) {
			return res;
		}

		stack<TreeNode *> stack;
		while (!stack.empty() || root != nullptr ) {
			while (root != nullptr) {
				res.push_back(root->val);
				stack.push(root);
				root = root->left;
			}
			root = stack.top();
			stack.pop();
			root = root->right;
		}
		return res;
	}

	/* 二叉树的中序遍历：按照访问左子树——根节点——右子树的方式遍历这棵树，而在访问左子树或者右子树的时候我们按照同样的方式遍历，直到遍历完整棵树。 */
	/* 递归实现 */
private:
	void inorder (TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		inorder (root->left, res);
		res.push_back(root->val);
		inorder (root->right, res);
	}

public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		return res;
	}

	/* 递归实现 */
public:
	vector<int> inorderTraversal_Iterate(TreeNode* root) {
		vector<int> res;
		stack<TreeNode *> stack;
		while (root != nullptr || !stack.empty()) {
			while (root != nullptr) {
				stack.push(root);
				root = root->left;
			}

			root = stack.top();
			stack.pop();
			res.push_back(root->val);
			root = root->right;
		}

		return res;
	}

};


int main_0mkj7 () {
	Solution sol;
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(6);
	root->right = new TreeNode(10);

	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(7);

	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(11);

	/* 前序遍历 */
	vector<int> res;

	cout << "pre order:" << endl;
	res = sol.preorderTraversal(root);
	print_vector(res);
	res.clear();

	res = sol.preorderTraversal_Iterate(root);
	print_vector(res);
	res.clear();

	/* 中序遍历 */
	cout << "in order:" << endl;
	res = sol.inorderTraversal(root);
	print_vector(res);
	res.clear();

	return 0;
}

