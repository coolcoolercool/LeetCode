//
// Created by rainyzwzhou on 2022/5/7.
//
#include "../../include.h"

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> levelQueue;
		levelQueue.push(root);
		int res = 0;
		while(!levelQueue.empty()) {
			int levelSize = levelQueue.size();
			for(int i = 0; i < levelSize; i++) {
				TreeNode *cur = levelQueue.front();
				levelQueue.pop();

				if (cur->left != nullptr) {
					levelQueue.push(cur->left);
				}

				if (cur->right != nullptr) {
					levelQueue.push(cur->right);
				}
			}
			res++;
		}

		return res;
	}

	int maxDepth_recu(TreeNode* root) {
		if(root == nullptr) return 0;

		return max(maxDepth_recu(root->left), maxDepth_recu(root->right)) + 1;
	}


};
