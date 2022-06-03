// Created by rainyzwzhou on 2022/5/30.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lco/solution/zui-jian-jie-yi-dong-de-dai-ma-tu-wen-bi-spxa/

中序遍历，左根右
逆着中序遍历，右根左
**/

#include "../../include.h"

class Solution {
public:
	int res;

	void help(TreeNode *root, int &k) {    //传引用 这里需要保证所有dfs函数共用一个k
		if (root == nullptr) return;
		help(root->right, k); //右
		k--;
		if (k == 0) res = root->val; //根
		help(root->left, k); //左
	}

	int kthLargest(TreeNode *root, int k) {
		help(root, k);
		return res;
	}
};
























