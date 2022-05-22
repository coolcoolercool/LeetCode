// Created by rainyzwzhou on 2022/5/14.

/**
题目描述:

核心思想:
 注意这里的直径，是两个节点之间所有节点数目 - 1，或者理解成边的个数

 通过计算当前节点的左子树和右子树中，选择其中节点较多的一个节点，(返回)
 后序遍历整个二叉树，并统计其中当前节点的左右子节点 + 自己节点的最大值(递归处理)
 最后直径等于节点数减一
**/
#include "../../include.h"

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int res = 0; // 统计最长路径中的节点数，直径数等于节点数-1
	// 后序遍历
	int depth(TreeNode* curNode) {
		if (curNode == nullptr) return 0;

		int left = depth(curNode->left); // 左儿子为根的子树的深度
		int right = depth(curNode->right); // 右儿子为根的子树的深度

		res = max(left + right + 1, res);  // 将每个节点最大直径(左子树深度+右子树深度)当前最大值比较并取大者
		return max(left, right) + 1; // 注意这里返回是左右子节点的较大的一个 + 1，路径只能返回一条，左或者右
	}

	int diameterOfBinaryTree(TreeNode* root) {
		if(root == nullptr) return 0;

		depth(root);
		return res - 1;
	}
};