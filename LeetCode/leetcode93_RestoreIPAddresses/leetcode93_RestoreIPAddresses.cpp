#include "../../include.h"


/*
 题目: 给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

https://leetcode-cn.com/problems/restore-ip-addresses/solution/dai-ma-sui-xiang-lu-93-fu-yuan-ip-di-zhi-pzjo/

题目的oneRes其实就是在原数字字符串中直接添加 '.'改造出来的
 */

class Solution {
private:
	vector<string> res;

	void dfs(string &str, int startIndex, int pointNum) {
		// 逗点数量为3时，分隔结束。判断第四段子字符串是否合法，如果合法就放进result中
		if (pointNum == 3) {
			if (isIllegalIpNum(str, startIndex, str.size() - 1)) {
				res.push_back(str);
			}
			return;
		}

		for (int i = startIndex; i < str.size(); i++) {
			if (isIllegalIpNum(str, startIndex, i)) {
				str.insert(str.begin() + i + 1, '.');
				pointNum++;

				dfs(str, i + 2, pointNum);

				str.erase(str.begin() + i + 1);
				pointNum--;
			}
		}
	}

	// 判断字符串s在左闭右闭区间[start, end]所组成的数字是否合法
	bool isIllegalIpNum(const string &str, int start, int end) {
		if (start > end) return false; // 因为字符串的长度每次会增加一位，但是分割线要后移两位，这就存在越界的问题。正常的递归中，有for作判断，而递归终止的时候，就是靠这个if来做越界的判断
		if (str[start] == '0' && start != end) return false; // 0开头的数字不合法

		int num = 0;
		for (int i = start; i <= end; i++) {
			if (str[i] > '9' || str[i] < '0') return false;  // 遇到非数字字符不合法

			num = num * 10 + (str[i] - '0');
			if (num > 255) return false; // 如果大于255了不合法

		}
		return true;
	}
public:
	vector<string> restoreIpAddresses(string s) {
		dfs(s, 0, 0);

		return res;
	}
};

int main_pmjh65() {
	Solution sol;
	string s = "25525511135";
	vector<string> res = sol.restoreIpAddresses(s);

	print_vector(res);

	return 0;
}




