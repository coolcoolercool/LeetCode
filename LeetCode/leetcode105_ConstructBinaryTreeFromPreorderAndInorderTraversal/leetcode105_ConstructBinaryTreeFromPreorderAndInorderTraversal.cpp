// Created by rainyzwzhou on 2022/5/7.

/**
题目描述:

核心思想:

 对于任意一颗树而言，前序遍历的形式总是
[ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]
即根节点总是前序遍历中的第一个节点。

 而中序遍历的形式总是
[ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]

 递归
(1)先序遍历的顺序是根节点，左子树，右子树。中序遍历的顺序是左子树，根节点，右子树。
(2)所以我们只需要根据先序遍历得到根节点，然后在中序遍历中找到根节点的位置，它的左边就是左子树的节点，右边就是右子树的节点。
(3)生成左子树和右子树就可以递归的进行了。
(4)但存在一个问题，在中序遍历中找到根节点的位置每次都得遍历中序遍历的数组去寻找，参考这里 ，我们可以用一个HashMap把中序遍历数组的每个元素的值和下标存起来，这样寻找根节点的位置就可以直接得到了
**/

#include "../../include.h"

class Solution {
private:
	unordered_map<int, int> mp;

public:
	TreeNode* myBuildTree(const vector<int> &preorder, const vector<int> &inorder, int preLeft, int preRight, int inLeft, int inRight) {
		if (preLeft > preRight) return nullptr;  // 注意这里的递归终止条件

		int preRootValue = preorder[preLeft]; // 前序遍历中的第一个节点就是根节点
		int inRoot = mp[preRootValue]; // 在中序遍历中定位根节点
		TreeNode *root = new TreeNode(preRootValue); // 先把根节点建立出来

		int leftSubSize = inRoot - inLeft; // 得到左子树中的节点数目
		// 递归地构造左子树，并连接到根节点
		// 先序遍历中「从 左边界+1 开始的 leftSubSize」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
		root->left = myBuildTree(preorder, inorder, preLeft + 1, preLeft + leftSubSize, inLeft, inRoot - 1);
		// 递归地构造右子树，并连接到根节点
		// 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
		root->right = myBuildTree(preorder, inorder, preLeft + leftSubSize + 1, preRight, inRoot + 1, inRight);
		return root;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int size = preorder.size();
		// 构造哈希映射，帮助我们快速定位根节点
		for (int i = 0; i < size; ++i) {
			mp[inorder[i]] = i;
		}
		return myBuildTree(preorder, inorder, 0, size - 1, 0, size - 1);
	}
};
