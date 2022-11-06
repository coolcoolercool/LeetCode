// Created by 周子望 on 2022/10/30.
#include "../../include.h"
/**
题目描述:

核心思想:
https://leetcode.cn/problems/range-addition-ii/solutions/1086781/fan-wei-qiu-he-ii-by-leetcode-solution-kcxq/

最终位置(0, 0)的值等于操作的次数

**/

class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		int mina = m, minb = n;
		for(vector<int> op : ops) {
			mina = min(mina, op[0]);
			minb = min(minb, op[1]);
		}
		return mina * minb;
	}
};