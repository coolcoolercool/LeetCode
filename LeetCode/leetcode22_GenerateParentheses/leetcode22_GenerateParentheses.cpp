#include "../../include.h"
/**
题目: 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。


如何设计dfs搜索函数？

最关键的问题在于搜索序列的当前位时，是选择填写左括号，还是选择填写右括号 ？
因为我们已经知道一个合法的括号序列，任意前缀中左括号数量一定 >= 右括号数量，因此，如果左括号数量不大于 n，
我们就可以放一个左括号，来等待一个右括号来匹配 。
如果右括号数量小于左括号的数量，我们就可以放一个右括号，来使一个右括号和一个左括号相匹配。

 n是括号对数，left是左括号数量，right是右括号数量，str是当前维护的合法括号序列。
搜索过程如下：
1、初始时定义序列的左括号数量left 和右括号数量right都为0。
2、如果 left < n，左括号的个数小于n，则在当前序列str后拼接左括号。
3、如果 left < n && left > right , 右括号的个数小于左括号的个数，则在当前序列str后拼接右括号。
4、当 left == n && right == n 时，将当前合法序列str加入答案数组res中。

1207

 */


class Solution {
	// dfs做。 当前括号序列中左括号数量小于N，可以继续添加左括号； 当前括号序列中右括号数量小于左括号数量，可以继续添加右括号。
public:
	vector<string> res;
	string oneRes;
	void help(int n, int left, int right) {
		if(left == n && right == n) {
			res.push_back(oneRes);
			return;
		} else {
			if(left < n) {  // 拼接左括号
				oneRes.push_back('(');
				help(n, left + 1, right);
				oneRes.pop_back();
			}

			if(right < n && right < left) {  // 注意这里的条件，left > right 才是合法的括号组合
				oneRes.push_back(')');
				help(n, left, right + 1);
				oneRes.pop_back();
			}
		}
	}

	vector<string> generateParenthesis(int n) {  // 这里n是括号对数，即生成的括号字符串长度为 2n
		string oneRes;
		help(n, 0, 0);
		return res;
	}
};
