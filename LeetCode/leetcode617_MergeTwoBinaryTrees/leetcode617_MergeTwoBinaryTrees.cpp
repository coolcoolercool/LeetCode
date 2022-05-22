// Created by rainyzwzhou on 2022/5/14.

/**
题目描述:

核心思想:
**/
#include "../../include.h"

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr) return root2;
		if (root2 == nullptr) return root1;
		auto merged = new TreeNode(root1->val + root2->val);

		merged->left = mergeTrees(root1->left, root2->left);
		merged->right = mergeTrees(root1->right, root2->right);

		return merged;
	}
};