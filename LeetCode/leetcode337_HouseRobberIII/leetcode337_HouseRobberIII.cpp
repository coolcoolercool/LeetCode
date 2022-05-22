// Created by rainyzwzhou on 2022/5/13.

/**
题目描述:

核心思想:
 一棵二叉树，树上的每个点都有对应的权值，每个点有两种状态（选中和不选中），问在不能同时选中有父子关系的点的情况下，能选中的点的最大权值和是多少。

我们可以用 f(o) 表示选择 o 节点的情况下，o 节点的子树上被选择的节点的最大权值和；g(o) 表示不选择 o 节点的情况下，oo 节点的子树上被选择的节点的最大权值和；l和 r 代表 o 的左右孩子。

当 o 被选中时，o 的左右孩子都不能被选中，故 o 被选中情况下子树上被选中点的最大权值和为 l 和 r 不被选中的最大权值和相加，即f(o)=g(l)+g(r)。
当 o 不被选中时，oo 的左右孩子可以被选中，也可以不被选中。对于 oo 的某个具体的孩子 xx，它对 oo 的贡献是 xx 被选中和不被选中情况下权值和的较大值。故  , g(o)=max{f(l),g(l)}+max{f(r),g(r)}。
至此，我们可以用哈希表来存 f 和 g 的函数值，用深度优先搜索的办法后序遍历这棵二叉树，我们就可以得到每一个节点的 f 和 g。根节点的 f 和 g 的最大值就是我们要找的答案。
**/

#include <bits/stdc++.h>
#include "../../include.h"
using namespace std;

class Solution {
public:
	unordered_map <TreeNode*, int> select, noSelect;

	// 后序遍历: 因为当前父节点的值，需要依赖子节点的值，因此需要子节点的值先算出来，即后序遍历
	void dfs(TreeNode* curNode) {
		if (!curNode) {
			return;
		}
		dfs(curNode->left);
		dfs(curNode->right);

		select[curNode] = curNode->val + noSelect[curNode->left] + noSelect[curNode->right];  // 选择当前节点，等于 当前节点 + 左右子节点
		noSelect[curNode] = max(select[curNode->left], noSelect[curNode->left]) + max(select[curNode->right], noSelect[curNode->right]); // 不选择当前节点，等于 选择和不选择 左子节点 较大者 + 选择和不选择 右子节点 的较大者
	}

	int rob(TreeNode* root) {
		dfs(root);
		return max(select[root], noSelect[root]);
	}
};
