// Created by rainyzwzhou on 2022/5/15.

/**
题目描述:
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其 最大路径和 。


核心思想:
 核心在于计算结果的时候要计算左右子树，递归返回的时候只能返回较大的一边
 因为最大路径只有一条，要不左边要不右边

 https://leetcode.cn/problems/binary-tree-maximum-oneRes-sum/solution/shou-hui-tu-jie-hen-you-ya-de-yi-dao-dfsti-by-hyj8/
**/

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int res = INT_MIN;

public:
	int maxGain(TreeNode* node) {
		if (node == nullptr) return 0;

		// 递归计算左右子节点的最大贡献值, 只有在最大贡献值大于 0 时，才会选取对应子节点
		int leftGain = max(maxGain(node->left), 0);
		int rightGain = max(maxGain(node->right), 0);

		// 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
		res = max(res, node->val + leftGain + rightGain); // 更新答案
		// 返回节点的最大贡献值，
		return node->val + max(leftGain, rightGain); // 核心。这里返回是当前节点加上左右子节点中较大贡献的一个
	}

	int maxPathSum(TreeNode* root) {
		maxGain(root);
		return res;
	}
};


