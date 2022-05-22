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
		int ans = 0;

		while(!levelQueue.empty()) {
			int levelSize = levelQueue.size();

			for(int i = 0; i < levelSize; i++) {
				TreeNode* tempNode = levelQueue.front();
				levelQueue.pop();

				if (tempNode->left != nullptr) {
					levelQueue.push(tempNode->left);
				}

				if(tempNode->right != nullptr) {
					levelQueue.push(tempNode->right);
				}
			}
			ans++;
		}

		return ans;
	}

	int maxDepth_recu(TreeNode* root) {
		if(root == nullptr) return 0;

		return max(maxDepth_recu(root->left), maxDepth_recu(root->right)) + 1;
	}

};
