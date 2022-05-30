// Created by rainyzwzhou on 2022/5/29.

/**
题目描述:
在一个完全二叉树中，除了最后一个关卡外，所有关卡都是完全被填满的，并且最后一个关卡中的所有节点都是尽可能靠左的。它可以包含1到2h节点之间的最后一级 h 。

 
核心思想:
层次遍历，空值也入队，当出队值为空时判断队列剩下元素是否都为空，为则完全二叉树
**/

#include "../../include.h"

class Solution {
	// 使用层次遍历来处理, 这里核心的变化，就是queue中允许压入为null的节点
	// 什么时候是不完全呢？其实就是出现null结点之后后面又出现了结点，如果是完全则最后一个null结点之后就结束遍历了
public:
	bool isCompleteTree(TreeNode *root) {
		queue<TreeNode *> lQueue;
		bool reachNull = false; // 记录是否已经遍历到null节点结果

		lQueue.push(root);
		while (!lQueue.empty()) {
			TreeNode *cur = lQueue.front();
			lQueue.pop();

			if (cur == nullptr) { // 第一次 发现空结点了
				reachNull = true;
				continue;
			}

			if (reachNull == true) return false; // 发现null结点后出现非空结点，发现不完全了

			lQueue.push(cur->left);
			lQueue.push(cur->right);
		}
		return true;
	}

	// 使用的节点数和最后一个节点的索引是否对应
	bool isCompleteTree_0(TreeNode *root) {
		queue<pair<TreeNode *, long long>> lQueue;
		lQueue.push({root, 1});

		long long res = 1;
		int nodeCnt = 0;
		while (!lQueue.empty()) {
			int size = lQueue.size();
			nodeCnt += size;

			for (int i = 0; i < size; i++) {
				TreeNode *cur = lQueue.front().first;
				long long val = lQueue.front().second;
				lQueue.pop();
				res = max(val, res);

				if (cur->left != nullptr) {
					lQueue.push({cur->left, 2 * val});
				}
				if (cur->right != nullptr) {
					lQueue.push({cur->right, 2 * val + 1});
				}
			}
		}
		return res == nodeCnt;
	}
};