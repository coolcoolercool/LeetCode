// Created by rainyzwzhou on 2022/5/14.

/**
题目描述:
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”


核心思想:
 考虑通过递归对二叉树进行先序遍历，当遇到节点 p 或 q 时返回。从底至顶回溯，当节点 p, q在节点 root的异侧时，节点 root 即为最近公共祖先，则向上返回 root 。
 https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solution/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu/

 根据 left 和 right ，可展开为四种情况；
（1）当 left 和 right 同时为空 ：说明 root 的左 / 右子树中都不包含 p,q ，返回 null ；
（2）当 left 和 right 同时不为空 ：说明 p, q 分列在 root 的 异侧 （分别在 左 / 右子树），因此 root 为最近公共祖先，返回 root ；
（3）当 left 为空 ，right 不为空 ：p,q 都不在 root 的左子树中，直接返回 right 。
 		具体可分为两种情况：
   		p,q 其中一个在 root 的 右子树 中，此时 right 指向 p（假设为 p ）；
		p,q 两节点都在 root 的 右子树 中，此时的 right 指向 最近公共祖先节点 ；
（4）当 left 不为空 ， right 为空 ：与情况 3. 同理；

作者：jyd
链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solution/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
**/

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;


class Solution {

	// 递归写法
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		if (root == nullptr || root == p || root == q) return root;  // 递归终止条件

		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);

		if (left == nullptr) return right;
		if (right == nullptr) return left;

		return root;
	}
};

