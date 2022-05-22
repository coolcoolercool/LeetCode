// Created by rainyzwzhou on 2022/5/13.

/**
题目描述:

核心思想:
 我们定义节点的前缀和为：由根结点到当前结点的路径上所有节点的和。我们利用先序遍历二叉树，记录下根节点 root 到当前节点 p 的路径上除当前节点以外所有节点的前缀和，在已保存的路径前缀和中查找是否存在前缀和刚好等于当前节点到根节点的前缀和 curr 减去 targetSum。
**/

#include "../../include.h"
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// 根节点 root 到当前节点 p 的路径上除当前节点p以外所有节点的前缀和，在已保存的路径前缀和中查找是否存在前缀和刚好等于当前节点到根节点的前缀和 curr 减去 targetSum

	unordered_map<long long, int> prefix; // key是前缀和, value是大小为key的前缀和出现的次数

	int dfs(TreeNode *root, long long curSum, int targetSum) {
		if (root == nullptr) return 0;

		int ret = 0;
		curSum += root->val;  // 当前路径上的和
		if (prefix.count(curSum - targetSum)) {  // currSum-target相当于找路径的起点，起点的sum+target=currSum，当前点到起点的距离就是target
			// 当前节点->root节点反推，有且仅有一条路径，如果此前有和为currSum-target,而当前的和又为currSum,两者的差就肯定为target了
			ret = prefix[curSum - targetSum]; // 可能会有多个，比如，A->B为0，B->C 等于 value，那么A->C 也等于value
		}

		prefix[curSum]++; // 更新

		// 进入下一层
		ret += dfs(root->left, curSum, targetSum);
		ret += dfs(root->right, curSum, targetSum);

		// 回到本层，恢复状态，去除当前节点的前缀数量
		prefix[curSum]--;

		return ret;
	}

	int pathSum(TreeNode* root, int targetSum) {
		prefix[0] = 1;  // 前缀和为0的一条路径
		return dfs(root, 0, targetSum);
	}


public:
	// 前序遍历每一个节点，对于每一个节点为根节点，再进行前序遍历，并计算其中满足 targetSum的情况数目
	int rootSum(TreeNode* root, int targetSum) {
		if (!root) {
			return 0;
		}

		int ret = 0;
		if (root->val == targetSum) {
			ret++;
		}

		ret += rootSum(root->left, targetSum - root->val);
		ret += rootSum(root->right, targetSum - root->val);
		return ret;
	}

	// 前序遍历
	int pathSum_0(TreeNode* root, int targetSum) {
		if (!root) {
			return 0;
		}

		int ret = rootSum(root, targetSum);
		ret += pathSum_0(root->left, targetSum);
		ret += pathSum_0(root->right, targetSum);
		return ret;
	}
};