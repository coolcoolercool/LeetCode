// Created by rainyzwzhou on 2022/5/15.

/**
题目描述:
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

核心思想:
 层次遍历，每一层的最后一个数字
**/

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if(root == nullptr) return res;

		queue<TreeNode*> levelQueue;
		levelQueue.push(root);
		while(!levelQueue.empty()) {
			int size = levelQueue.size();

			for(int i = 0; i < size; i++) {
				TreeNode* temp = levelQueue.front();
				levelQueue.pop();

				if(temp->left != nullptr) levelQueue.push(temp->left);
				if(temp->right != nullptr) levelQueue.push(temp->right);

				if (i == size - 1) res.push_back(temp->val);
			}
		}

		return res;
	}
};