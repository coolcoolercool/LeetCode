#include "../../include.h"


/*
 题目: 给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

https://leetcode-cn.com/problems/restore-ip-addresses/solution/dai-ma-sui-xiang-lu-93-fu-yuan-ip-di-zhi-pzjo/

 */


class Solution {
private:
	vector<string> res;

	/**
	 *
	 * @param s
	 * @param startIndex 搜索的起始位置
	 * @param pointNum 添加逗号的数量，添加三个ip就切分完成
	 */
	void dfs (string& s, int startIndex, int pointNum) {
		// 逗点数量为3时，分隔结束。判断第四段子字符串是否合法，如果合法就放进result中
		if (pointNum == 3) {
			if (isIllegalIpNum(s, startIndex, s.size() - 1)) {
				res.push_back(s);
			}
			return;
		}

		for (int i = startIndex; i < s.size(); i++) {
			if (isIllegalIpNum(s, startIndex, i)) {
				s.insert(s.begin() + i + 1, '.');
				pointNum++;

				dfs(s, i + 2, pointNum);

				s.erase(s.begin() + i + 1);
				pointNum--;
			} else {
				break;
			}
		}
	}
	// 判断字符串s在左闭右闭区间[start, end]所组成的数字是否合法
	bool isIllegalIpNum (const string& s, int start, int end) {
		if (start > end) {
			return false;
		}
		if (s[start] == '0' && start != end) { // 0开头的数字不合法
			return false;
		}
		int num = 0;
		for (int i = start; i <= end; i++) {
			if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
				return false;
			}
			num = num * 10 + (s[i] - '0');
			if (num > 255) { // 如果大于255了不合法
				return false;
			}
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




