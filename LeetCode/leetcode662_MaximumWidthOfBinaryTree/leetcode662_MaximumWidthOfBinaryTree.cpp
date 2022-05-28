// Created by rainyzwzhou on 2022/5/17.

/**
题目描述:

核心思想:
 为涉及一层一层的遍历，基本想到就是广度优先

思路：
(1)宽度优先会使用一个queue，而这个queue就可以帮助我们计算出目前层的宽度
(2)数值转换(关键一步，减少内存，加速计算)：为了计算宽度，我们需要记录每个节点出现的编号， 比如[1,3,2] 这样的二叉树，对应 1->0 3->0 2->1
(3)下一层，基于当前层的编号推出下一层：
	left: parent->val * 2
	right: parent->val * 2 +1
(4)当前层的宽度： back-val - front->val + 1
	如 front->0 back=4, 那么宽度就是5
(5)额外，为了避免数字过大，我们会让val每次基于queue front编号做缩小
	queue front的编号是100
	front缩小为 100-100=0， 后续每个编号都需要减去100


解法概括:
层序遍历的应用，完全二叉树编号技巧left = parent*2， right= parent*2+1

**/

#include "../../include.h"
#include <bits/stdc++.h>
using namespace std;

//层次遍历解法
class Solution {
public:
	//由于官方更新了测试用例，导致用原本二叉树的val记录编号（int型）会造成溢出。
	int widthOfBinaryTree(TreeNode *root) {
		if (root == nullptr) return 0; //如果为空树，直接返回0；
		queue<pair<TreeNode *, long long>> levelQueue; //队列记录二叉树的结点和一个对应的long long型编号. 注意这里不是 long long 用例会报错的
		int res = 0; //保存结果
		levelQueue.push({root, 0}); //根节点入队，并记录对应编号

		while (!levelQueue.empty()) {
			res = max(res, (int) (levelQueue.back().second - levelQueue.front().second + 1)); //更新每层宽度最大值，注意这里加一

			int size = levelQueue.size(); //每一层结点数
			int offset = levelQueue.front().second; //以每层第一个结点的值为偏移值，保持每层结点之间的相对关系，缩小索引
			for (int i = 0; i < size; i++) {
				root = levelQueue.front().first;
				long long val = levelQueue.front().second; //获取root结点对应的编号   注意这里不是 long long 用例会报错的
				levelQueue.pop();
				val -= offset; //缩小编号索引

				if (root->left) levelQueue.push({root->left, val * 2});//左孩子的编号为parent编号*2
				if (root->right) levelQueue.push({root->right, val * 2 + 1}); //右孩子的编号为parent编号*2+1
			}
		}
		return res;
	}
};
