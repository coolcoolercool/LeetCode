// Created by rainyzwzhou on 2022/5/19.

/**
题目描述:

核心思想:
递归: 深度优先搜索
 用一个参数i表示：从根节点到父节点的路径和，此时对于目前节点来说，路径和为10*i+node.val

从根节点开始，遍历每个节点，如果遇到叶子节点，则将叶子节点对应的数字加到数字之和。如果当前节点不是叶子节点，则计算其子节点对应的数字，然后对子节点递归遍历。


迭代: 广度优先搜索
使用广度优先搜索，需要维护两个队列，分别存储节点和节点对应的数字。
初始时，将根节点和根节点的值分别加入两个队列。每次从两个队列分别取出一个节点和一个数字，进行如下操作：
(1)如果当前节点是叶子节点，则将该节点对应的数字加到数字之和；
(2)如果当前节点不是叶子节点，则获得当前节点的非空子节点，并根据当前节点对应的数字和子节点的值计算子节点对应的数字，然后将子节点和子节点对应的数字分别加入两个队列。

搜索结束后，即可得到所有叶子节点对应的数字之和。

**/

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
	// 层次遍历，queue中存储是节点和节点对应的数字之和，当遇到叶子节点的时候，累计
public:
	int sumNumbers(TreeNode *root) {
		if (root == nullptr) return 0;

		queue<pair<TreeNode *, int>> lQueue;
		lQueue.push({root, root->val});

		int res = 0;
		while (!lQueue.empty()) {
			int size = lQueue.size();

			for (int i = 0; i < size; i++) {
				TreeNode *cur = lQueue.front().first;
				int sum = lQueue.front().second;
				lQueue.pop();

				if (cur->left == nullptr && cur->right == nullptr) {
					res += sum;
				} else {
					if (cur->left != nullptr) {
						lQueue.push({cur->left, sum * 10 + cur->left->val});
					}
					if (cur->right != nullptr) {
						lQueue.push({cur->right, sum * 10 + cur->right->val});
					}
				}
			}
		}

		return res;
	}


	// 迭代，层次遍历，新增一个保存从根节点到当前节点的
public:
	int sumNumbers_bfs(TreeNode *root) {
		if (root == nullptr) return 0;
		int sum = 0;
		queue<TreeNode *> nodeQueue;
		queue<int> valQueue;
		nodeQueue.push(root);
		valQueue.push(root->val);

		while(!nodeQueue.empty()) {
			TreeNode* cur = nodeQueue.front();
			int val = valQueue.front();
			nodeQueue.pop();
			valQueue.pop();

			TreeNode* left = cur->left;
			TreeNode* right = cur->right;
			if(left == nullptr && right == nullptr) {
				sum += val;
			} else {
				if(left != nullptr) {
					nodeQueue.push(left);
					valQueue.push(val * 10 + left->val);
				}

				if(right != nullptr) {
					nodeQueue.push(right);
					valQueue.push(val * 10 + right->val);
				}
			}
		}

		return sum;
	}


	// 递归写法
public:
	int help(TreeNode *root, int sum) {
		if (root == nullptr) return 0;
		sum = sum * 10 + root->val;
		if (root->left == nullptr && root->right == nullptr) {
			return sum;
		} else {
			return help(root->left, sum) + help(root->right, sum);
		}
	}

	int sumNumbers_dfs(TreeNode* root) {
		return (help(root, 0));
	}
};