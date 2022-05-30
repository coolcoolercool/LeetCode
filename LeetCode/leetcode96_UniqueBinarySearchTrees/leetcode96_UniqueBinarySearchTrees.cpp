// Created by 周子望 on 2021/11/17

/*
 题目: 不同二叉搜索树  BST
 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

 使用中序遍历来遍历二叉树，在遍历的过程中判断是否符合二叉搜索树
 中序遍历：左子树---> 根结点 ---> 右子树

 核心思想:
 给定一个有序序列  n1⋯n，为了构建出一棵二叉搜索树，我们可以遍历每个数字 i，将该数字作为树根，
 将 1⋯(i−1) 序列作为左子树，将 (i+1)⋯n 序列作为右子树。接着我们可以按照同样的方式递归构建左子树和右子树。

在上述构建的过程中，由于根的值不同，因此我们能保证每棵二叉搜索树是唯一的。
https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode-solution/
 */

#include "../../include.h"

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}

		return dp[n];
	}
};