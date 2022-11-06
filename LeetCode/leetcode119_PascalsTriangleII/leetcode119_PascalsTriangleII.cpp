// Created by 周子望 on 2022/10/30.
#include "../../include.h"
/**
题目描述:

核心思想:
杨辉三角的特性:
https://leetcode.cn/problems/pascals-triangle/solutions/510638/yang-hui-san-jiao-by-leetcode-solution-lew9/

**/

class Solution {
public:
	vector<int> getRow_ver0(int rowIndex) {
		vector<vector<int>> res(rowIndex + 1);

		for(int i = 0; i <= rowIndex; i++) {
			res[i].resize(i + 1);
			res[i][0] = res[i][i] = 1;

			for(int j = 1; j < i; j++) {
				res[i][j] = res[i][j - 1] + res[i][j];
			}
		}
		return res[rowIndex];
	}

	// 滚动数组
	vector<int> getRow_ver1(int rowIndex) {
		vector<int> pre, cur;
		for(int i = 0; i <= rowIndex; i++) {
			cur.resize(i + 1);
			cur[0] = cur[i] = 1;
			for(int j = 1; j < i; j++) {
				cur[j] = pre[j - 1] + pre[j];
			}
			pre = cur;
		}
		return pre;
	}

	// 可以倒着计算当前行，这样计算到第 i 项时，第 i−1 项仍然是上一行的值
	vector<int> getRow_ver2(int rowIndex) {
		vector<int> res(rowIndex + 1);
		res[0] = 1;
		for(int i = 0; i <= rowIndex; i++) {
			for(int j = i; j > 0; j--) {
				res[j] = res[j - 1] + res[j];
			}
		}
		return res;
	}
};