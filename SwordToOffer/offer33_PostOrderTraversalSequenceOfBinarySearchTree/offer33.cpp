// Created by rainyzwzhou on 2022/5/30.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/mian-shi-ti-33-er-cha-sou-suo-shu-de-hou-xu-bian-6/
很类似根据前序和中序遍历，重构二叉树的思想

递归+分治
后序遍历:  左子树 | 右子树 | root节点
结合二叉搜索树性质:     左子树节点值 < root节点值 | 右子树节点值 > root节点值 | root节点
思想: 因此我们可以划分左右子树和root节点，采用递归分治 并借助上一性质 来判断是否为二叉搜索树
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	// 递归写法
private:
	bool help(vector<int> &postorder, int left, int right) { // left、right 为当前树所有节点 在数组postorder中的下标范围
		if (left >= right) return true;     // 当前树节点数为1，返回true
		int root = postorder[right];        // 因为是后续遍历，所以当前树的root节点值为postorder[right]
		int i = right - 1;
		while (i >= 0 && root < postorder[i])
			--i;   // 从root节点前一个节点开始 往前找右子树，直到出现不满足root < postorder[i]，说明进入了左子树范围; 或者i<0，说明只有右子树
		int mid = i;                                 // mid为左子树的right（mid>=0时）
		while (i >= 0 && root > postorder[i]) --i;   // 接着找左子树

		if (i >= 0) return false;    //  先找右子树，再找左子树，但如果此时i>=0，说明该树不满足二叉搜索树性质！（按道理来说i=-1）

		return help(postorder, left, mid) && help(postorder, mid + 1, right - 1);    // 根据mid划分左右子树，继续往下找左右子树
	}

public:
	bool verifyPostorder(vector<int> &postorder) {
		if (postorder.empty()) return true;       // 习惯性判空

		return help(postorder, 0, postorder.size() - 1);      // 递归判断
	}
};

class Solution_diedai {
	// 迭代写法
public:
	bool verifyPostorder(vector<int> &postorder) {
		int size = postorder.size();
		stack<int> st;
		int root = INT_MAX;

		for (int i = size - 1; i >= 0; i--) {
			if (postorder[i] > root) return false;

			while (!st.empty() && st.top() > postorder[i]) {
				root = st.top();
				st.pop();
			}
			st.push(postorder[i]);
		}

		return true;
	}
};


