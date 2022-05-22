// Created by rainyzwzhou on 2022/5/14.

/**
题目描述:
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

 Z字层序遍历打印二叉树

核心思想:
**/

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> res;
		if (root == nullptr) return res;

		queue<TreeNode *> levelQueue;
		levelQueue.push(root);
		bool flag = true; // 从左到右
		while (!levelQueue.empty()) {
			int size = levelQueue.size();
			vector<int> oneLevel;

			for (int i = 0; i < size; i++) {
				TreeNode *temp = levelQueue.front();
				levelQueue.pop();
				oneLevel.push_back(temp->val);

				if (temp->left != nullptr) {
					levelQueue.push(temp->left);
				}
				if (temp->right != nullptr) {
					levelQueue.push(temp->right);
				}
			}
			if (!flag) reverse(oneLevel.begin(), oneLevel.end());

			flag = !flag;
			res.push_back(oneLevel);
		}

		return res;
	}

	// 使用了双端队列，flag为true，就从尾部插入，flag为false，就从头部插入
	vector<vector<int>> zigzagLevelOrder_0(TreeNode *root) {
		vector<vector<int>> res;
		if (root == nullptr) return res;

		queue<TreeNode *> levelQueue;
		levelQueue.push(root);
		bool flag = true; // 从左到右
		while (!levelQueue.empty()) {
			int size = levelQueue.size();
			deque<int> oneLevel;

			for (int i = 0; i < size; i++) {
				TreeNode *temp = levelQueue.front();
				levelQueue.pop();
				if(flag) {
					oneLevel.push_back(temp->val);
				} else {
					oneLevel.push_front(temp->val);
				}

				if (temp->left != nullptr) {
					levelQueue.push(temp->left);
				}
				if (temp->right != nullptr) {
					levelQueue.push(temp->right);
				}
			}

			flag = !flag;
			res.push_back(vector<int>{oneLevel.begin(), oneLevel.end()});
		}

		return res;
	}
};