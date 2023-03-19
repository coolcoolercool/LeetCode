// Created by 周子望 on 2022/9/12.

#include "../../include.h"

/**
题目描述:

 注意这里的Z是横着的Z

核心思想:
找规律的题目，这里的视频解说很清晰了
https://leetcode.cn/problems/zigzag-conversion/solution/zzi-xing-bian-huan-by-jyd/

**/

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		vector<string> rows(numRows); // 防止s的长度小于行数, 目前从leetcode用例上不用这个
		int curRow = 0;
		bool downOrUp = false;

		for(char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) {
				downOrUp = !downOrUp;
			}
			curRow += downOrUp ? 1 : - 1;
		}

		string res;
		for(string row : rows) {
			res += row;
		}
		return res;
	}
};