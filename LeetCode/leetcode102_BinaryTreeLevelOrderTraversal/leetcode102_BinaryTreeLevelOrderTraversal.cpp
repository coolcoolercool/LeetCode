//
// Created by rainyzwzhou on 2022/4/26.
//

/**
 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 二叉树的层次遍历
 */

#include "../../include.h"

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr) {
			return res;
		}

		queue<TreeNode*> queueLevel;
		queueLevel.push(root);

		while(!queueLevel.empty()) {
			vector<int> tempArr;
			int size = queueLevel.size();  // 这里必须事前取的本层节点的数目，因为queueLevel的size会变化

			for(int i = 0; i < size; i++) {
				TreeNode* node = queueLevel.front();
				queueLevel.pop();
				tempArr.push_back(node->val);

				if (node->left != nullptr) {
					queueLevel.push(node->left);
				}
				if (node->right != nullptr) {
					queueLevel.push(node->right);
				}
			}
			res.push_back(tempArr);
		}

		return res;
	}
};