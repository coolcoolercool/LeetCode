#include "../../include.h"

/**
 二叉树的前序遍历
 https://leetcode.cn/problems/binary-tree-preorder-traversal/

 二叉树的中序遍历
 https://leetcode.cn/problems/binary-tree-inorder-traversal/

 二叉树的后序遍历
 https://leetcode.cn/problems/binary-tree-postorder-traversal/

 二叉树的层次遍历
 https://leetcode.cn/problems/binary-tree-level-order-traversal/
 **/

class Solution {
public:
	// 递归部分
	/*
		递归是二叉树遍历实现中最简单的，二叉树天然就具有递归的属性，对每个结点的处理完全一样，二叉树可以称得上是思路最清晰的递归题目。
	 只要简单排布“调用左结点递归函数、调用右结点递归函数、输出本结点”这三个步骤就能完成递归操作。
	 */

	// 前序遍历 中左右：输出本结点->调用左递归->调用右递归
	void preorder(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		res.push_back(root->val);
		preorder(root->left, res);
		preorder(root->right, res);
	}

	vector<int> preorderTraversal_recu(TreeNode* root) {
		vector<int> res;
		preorder(root, res);
		return res;
	}

	// 中序遍历: 左中右：调用左递归->输出本结点->调用右递归
	void inorder(TreeNode* root, vector<int>& res) {
		if(root == nullptr) {
			return;
		}
		inorder(root->left, res);
		res.push_back(root->val);
		inorder(root->right, res);
	}

	vector<int> inorderTraversal_recu(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		return res;
	}

	// 二叉树的后序遍历：按照访问左子树——右子树——根节点的方式遍历这棵树，而在访问左子树或者右子树的时候，我们按照同样的方式遍历，直到遍历完整棵树
	void postorder(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		postorder(root->left, res);
		postorder(root->right, res);
		res.push_back(root->val);
	}

	vector<int> postorderTraversal_recu(TreeNode *root) {
		vector<int> res;
		postorder(root, res);
		return res;
	}

	// 非递归部分，迭代部分 ------------------------------------
	/*
	while( 栈非空 || p 非空) {
		while ( p 非空) {

		}
		else {

		}
	}

	vector<int> Traversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> stk;
		while(root != nullptr || !stk.empty()) {
			while(root != nullptr) {
				stk.push(root);
				// 前序遍历，这里加
				root = root->left;
			}
			root = stk.top();
			stk.pop();
			// 中序遍历，这里加
			root = root->right;
		}
		return res;
	}
	*/


	// 前序遍历 迭代 中左右：输出本结点->调用左递归->调用右递归
	// 递归的时候隐式地维护了一个栈，而我们在迭代的时候需要显式地将这个栈模拟出来，其余的实现与细节都相同
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) {
			return res;
		}
		stack<TreeNode*> stk;
		TreeNode* node = root;
		while(!stk.empty() || node != nullptr) {
			while(node != nullptr) {
				stk.push(node);
				res.push_back(node->val);
				node = node->left;
			}
			node = stk.top(); //如果右子树没有被访问，那么将当前节点压栈，访问右子树
			stk.pop();
			node = node->right;
		}
		return res;
	}

	// 中序遍历，迭代: 左中右：调用左递归->输出本结点->调用右递归
	// 递归函数我们也可以用迭代的方式实现，两种方式是等价的，区别在于递归的时候隐式地维护了一个栈，而我们在迭代的时候需要显式地将这个栈模拟出来，其他都相同，具体实现可以看下面的代码。
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> stk;
		while(root != nullptr || !stk.empty()) {
			while(root != nullptr) {
				stk.push(root);
				root = root->left;
			}
			//从栈中弹出的元素，左子树一定是访问完了的
			root = stk.top();
			stk.pop();
			res.push_back(root->val);
			root = root->right;
		}
		return res;
	}

	// 后序遍历: 左子树 -> 右子树 -> 根节点的方式
	/*
	 栈遍历版本： 建议先做中序遍历，后序只是在中序上多了一些操作。
	 与中序的不同之处在于：
		(1)中序遍历中，从栈中弹出的节点，其左子树是访问完了，可以直接访问该节点，然后接下来访问右子树。
		(2)后序遍历中，从栈中弹出的节点，我们只能确定其左子树肯定访问完了，但是无法确定右子树是否访问过。
	 因此，我们在后序遍历中，引入了一个prev来记录历史访问记录。
		(1)当访问完一棵子树的时候，我们用prev指向该节点。
		(2)这样，在回溯到父节点的时候，我们可以依据prev是指向左子节点，还是右子节点，来判断父节点的访问情况。

	  二叉树的非递归难点其实就在于后序遍历，因为后序需要两次路过根节点。遍历的时候需要根据第几次路过来决定是否访问根节点。解决的办法是增加一个r指针，指向上次访问的节点。因为后序遍历LRN最后一定是遍历根节点，所以当r指向root.right的时候那么就是该遍历root的时候了
	 */
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		if (root == nullptr) return res;

		stack<TreeNode *> st;
		TreeNode *pre = nullptr;
		while (root != nullptr || !st.empty()) {
			while (root != nullptr) {
				st.push(root);
				root = root->left;
			}
			// 从栈中弹出的元素，左子树一定是访问完了的
			root = st.top();
			st.pop();

			// 现在需要确定的是是否有右子树，或者右子树是否访问过
			// 如果没有右子树，或者右子树访问完了，也就是上一个访问的节点是右子节点时
			// 说明可以访问当前节点

			// 遍历最左子节点的右子树(右子树存在 && 未访问过)
			if (root->right == nullptr || root->right == pre) {
				// 后序：填充res在cur->left和cur->right后面
				// 注意：此时cur的左右子树应均已完成访问
				res.push_back(root->val);
				pre = root; // 避免重复访问右子树[记录当前节点便于下一步对比]
				root = nullptr;  // 避免重复访问左子树[设空节点]
			} else { // root->right != nullptr && root->right != pre
				st.push(root);    // 重复压栈以记录当前路径分叉节点
				root = root->right;
			}
		}

		return res;
	}


	// 二叉树的层次遍历
	/*
	 广度优先搜索：
	首先根元素入队
	当队列不为空的时候
		求当前队列的长度 si
	    依次从队列中取 si  个元素进行拓展，然后进入下一次迭代

	 */
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr) {
			return res;
		}
		queue<TreeNode*> que;
		que.push(root);
		while(!que.empty()) {
			int currentLevelSize = que.size();  /* 计算队列的大小也即有多少个孩子 */
			vector<int> temp;                   /* 定义一个临时vector 存储每一层 */

			for (int i = 0; i < currentLevelSize; i++) {
				TreeNode* node = que.front();
				que.pop();
				temp.push_back(node->val);

				// 将下一层的节点放入到队列中
				if(node->left != nullptr) {
					que.push(node->left);
				}
				if(node->right != nullptr) {
					que.push(node->right);
				}
			}
			res.push_back(temp);
		}
		return res;
	}
};

/*
emplace_back()和push_back()的区别
emplace_back() 和 push_back() 的区别，就在于底层实现的机制不同。push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；而 emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。

 emplace_back()
 该函数是 C++ 11 新增加的，其功能和 push_back() 相同，都是在 vector 容器的尾部添加一个元素。

 */